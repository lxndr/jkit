#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <new>
#include <utility>


namespace g3d {


template <typename KEY_TYPE, typename VALUE_TYPE>
class G3D_PUBLIC_API Map
{
public:
	/**
	 * @brief Constructs an empty Array.
	 */
	inline Map()
		: mKeys(nullptr), mValues(nullptr), mCount(0), mReserved(0)
	{}
	
	
	/**
	 * 
	 */
	inline Map(const Map<KEY_TYPE, VALUE_TYPE>& map) : Map()
		{copy(map);}
	
	
	/**
	 * 
	 */
	inline ~Map()
	{
		if (mCount)
			removeAll();
		
		if (mValues) {
			free(mValues);
			free(mKeys);
		}
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
	inline void set(int index, const VALUE_TYPE& value)
	{
		assert(index >= 0 && index < mCount);
		mValues[index] = value;
	}
	
	
	/**
	 * 
	 */
	inline void set(const KEY_TYPE& key, const VALUE_TYPE& value)
	{
		int index = indexOf(key);
		if (index > -1)
			set(index, value);
		else
			append(key, value);
	}
	
	
	/**
	 * @brief Gets value at index.
	 */
	inline VALUE_TYPE& get(int index)
	{
		assert(index >= 0 && index < mCount);
		return mValues[index];
	}
	
	
	/**
	 * @brief Gets const value at index.
	 */
	inline const VALUE_TYPE& get(int index) const
	{
		assert(index >= 0 && index < mCount);
		return mValues[index];
	}
	
	
	/**
	 * @brief Gets value at index.
	 */
	inline VALUE_TYPE& operator[](int index)
		{return get(index);}
	
	
	/**
	 * @brief Gets const value at index.
	 */
	inline const VALUE_TYPE& operator[](int index) const
		{return get(index);}
	
	
	/**
	 * @brief Gets value at key.
	 */
	inline VALUE_TYPE& get(const KEY_TYPE& key)
		{return get(indexOf(key));}
	
	
	/**
	 * @brief Gets const value at key.
	 */
	inline const VALUE_TYPE& get(const KEY_TYPE& key) const
		{return get(indexOf(key));}
	
	
	/**
	 * @brief Gets value at key.
	 */
	inline VALUE_TYPE& operator[](const KEY_TYPE& key)
		{return get(key);}
	
	
	/**
	 * @brief Gets const value at key.
	 */
	inline const VALUE_TYPE& operator[](const KEY_TYPE& key) const
		{return get(key);}
	
	
	/**
	 * 
	 */
	inline const KEY_TYPE& getKey(int index) const
	{
		assert(index >= 0 && index < mCount);
		return mKeys[index];
	}
	
	
	/**
	 * @brief Finds value in the Array.
	 * @param value the value to look for
	 * @return index if value is found, -1 if it is not
	 */
	int find(const VALUE_TYPE& value)
	{
		for (int i = 0; i < mCount; i++)
		if (get(i) == value)
			return i;
		return -1;
	}
	
	
	/**
	 * @brief Finds index of key.
	 * @param key the key to look for
	 * @return index if key is found, -1 if it is not
	 */
	int indexOf(const KEY_TYPE& key)
	{
		for (int i = 0; i < mCount; i++)
		if (getKey(i) == key)
			return i;
		return -1;
	}
	
	
	template<typename... Params>
	int append(const KEY_TYPE& key, Params&&... params)
	{
		int index = mCount;
		resize(mCount + 1);
		new(&mKeys[index]) KEY_TYPE(key);
		new(&mValues[index]) VALUE_TYPE(std::forward<Params>(params)...);
		return index;
	}
	
	
	/**
	 * 
	 */
	void remove(int index)
	{
		assert(0 <= index && index < mCount);
		
		(&mValues[index])->~VALUE_TYPE();
		memmove(mValues + index, mValues + index + 1,
				sizeof(VALUE_TYPE) * (mCount - index - 1));
		
		(&mKeys[index])->~KEY_TYPE();
		memmove(mKeys + index, mKeys + index + 1,
				sizeof(KEY_TYPE) * (mCount - index - 1));
		
		resize(mCount - 1);
	}
	
	
	/**
	 * 
	 */
	void remove(const KEY_TYPE& key)
	{
		int idx = indexOf(key);
		if (idx > -1)
			remove(idx);
	}
	
	
	/**
	 * 
	 */
	void removeAll()
	{
		for (int i = 0; i < mCount; i++) {
			(&mKeys[i])->~KEY_TYPE();
			(&mValues[i])->~VALUE_TYPE();
		}
		resize(0);
	}
	
	
	/**
	 * 
	 */
	void copy(const Map<KEY_TYPE, VALUE_TYPE>& map)
	{
		removeAll();
		for (int i = 0; i < map.getCount(); i++)
			append(map.getKey(i), map.get(i));
	}
	
	
	/**
	 * 
	 */
	Map<KEY_TYPE, VALUE_TYPE>& operator=(const Map<KEY_TYPE, VALUE_TYPE>& map)
	{
		copy(map);
		return *this;
	}
	
private:
	KEY_TYPE* mKeys;
	VALUE_TYPE* mValues;
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
			mKeys = (KEY_TYPE*) realloc(mKeys, mReserved * sizeof(KEY_TYPE));
			mValues = (VALUE_TYPE*) realloc(mValues, mReserved * sizeof(VALUE_TYPE));
		}
		mCount = size;
	}
};


}


#endif
