#ifndef __JKIT__ARRAY_HPP__
#define __JKIT__ARRAY_HPP__

#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <new>
#include <utility>


namespace J {


/**
 * Now it is a badass Array class.
 */

template <typename TYPE>
class JKIT_PUBLIC_API Array
{
public:
	/**
	 * @brief Constructs an empty Array.
	 */
	inline Array()
		: mValues(nullptr), mCount(0), mReserved(0)
	{}
	
	
	/**
	 * @brief Constructs a copy of array
	 */
	inline Array(const Array<TYPE>& array) : Array()
		{copy(array);}
	
	
	/**
	 * 
	 */
	inline ~Array()
	{
		if (mCount)
			removeAll();
		if (mValues)
			free(mValues);
	}
	
	
	/**
	 * @brief Gets number of values.
	 */
	inline int getCount() const
	{
		return mCount;
	}
	
	
	/**
	 * @brief Sets value at index.
	 */
	inline void set(int index, const TYPE& value)
	{
		assert(index >= 0 && index < mCount);
		mValues[index] = value;
	}
	
	
	/**
	 * @brief Gets value at index.
	 */
	inline TYPE& get(int index)
	{
		assert(index >= 0 && index < mCount);
		return mValues[index];
	}
	
	
	/**
	 * @brief Gets const value at index.
	 */
	inline const TYPE& get(int index) const
	{
		assert(index >= 0 && index < mCount);
		return mValues[index];
	}
	
	
	/**
	 * @brief Gets value at index.
	 */
	inline TYPE& operator[](int index)
		{return get(index);}
	
	
	/**
	 * @brief Gets const value at index.
	 */
	inline const TYPE& operator[](int index) const
		{return get(index);}
	
	
	/**
	 * @brief Finds value in the Array.
	 * @param value the value to look for
	 * @return index if value is found, -1 if it is not
	 */
	int find(const TYPE& value) const
	{
		for (int i = 0; i < mCount; i++)
		if (get(i) == value)
			return i;
		return -1;
	}
	
	
	/**
	 * 
	 */
	template<typename... Params>
	TYPE& insert(int index, Params&&... params)
	{
		assert(index < mCount);
		
		resize(mCount + 1);
		memmove(mValues + index + 1, mValues + index,
				sizeof(TYPE) * (mCount - index - 1));
		new(&mValues[index]) TYPE(std::forward<Params>(params)...);
		return get(index);
	}
	
	
	/**
	 * @brief Constructs a new value at the end of the Array.
	 * @return reference of the new value.
	 */
	template<typename... Params>
	TYPE& append(Params&&... params)
	{
		int index = mCount;
		resize(mCount + 1);
		new(&mValues[index]) TYPE(std::forward<Params>(params)...);
		return get(mCount - 1);
	}
	
	
	/**
	 * 
	 */
	int append(const TYPE& value)
	{
		int index = mCount;
		resize(mCount + 1);
		new(&mValues[index]) TYPE(value);
		return index;
	}
	
	
	/**
	 * 
	 */
	void append(const Array<TYPE>& array)
	{
		for (int i = 0; i < array.getCount(); i++)
			append(array[i]);
	}
	
	
	/**
	 * 
	 */
	inline void operator+=(const Array<TYPE>& array)
		{append(array);}
	
	
	/**
	 * 
	 */
	void remove(int index)
	{
		assert(0 <= index && index < mCount);
		
		(&mValues[index])->~TYPE();
		memmove(mValues + index, mValues + index + 1,
				sizeof(TYPE) * (mCount - index - 1));
		resize(mCount - 1);
	}
	
	
	/**
	 * 
	 */
	void remove(const TYPE& value)
	{
		int i = find(value);
		if (i != -1)
			remove(i);
	}
	
	
	/**
	 * 
	 */
	void remove(const TYPE* value)
	{
		assert((value >= mValues) && (value < mValues + sizeof(TYPE) * mCount));

		value->~TYPE();
		memmove(value, value + sizeof(TYPE),
				(mValues + sizeof(TYPE) * mCount) - (value + sizeof(TYPE)));
		resize(mCount - 1);
	}
	
	
	/**
	 * 
	 */
	void removeAll()
	{
		for (int i = 0; i < mCount; i++)
			(&mValues[i])->~TYPE();
		resize(0);
	}
	
	
	/**
	 * 
	 */
	void copy(const Array<TYPE>& array)
	{
		removeAll();
		for (int i = 0; i < array.getCount(); i++)
			append(array[i]);
	}
	
	
	/**
	 * 
	 */
	inline Array<TYPE>& operator=(const Array<TYPE>& array)
	{
		copy(array);
		return *this;
	}
	
private:
	TYPE* mValues;
	int mCount;
	int mReserved;

private:
	/*
	 * Reallocates memory.
	 */
	void resize(int size)
	{
		assert(size >= 0);
		
		if (size > mReserved) {
			mReserved = size + 16;
			mValues = (TYPE*) realloc(mValues, mReserved * sizeof(TYPE));
		}
		mCount = size;
	}
};



#define foreach(value, array)	\
		for(int i = 0; i < array.getCount(); i++) {	\
			auto value = array[i];
#define end_foreach()	\
		}


}


#endif
