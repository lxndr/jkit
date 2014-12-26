#ifndef __JKIT__CORE__ARRAY_HPP__
#define __JKIT__CORE__ARRAY_HPP__

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
		: m_Values(nullptr), m_Count(0), m_Reserved(0)
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
		if (m_Count)
			removeAll();
		if (m_Values)
			free(m_Values);
	}
	
	
	/**
	 * @brief Gets number of values.
	 */
	inline int count() const
	{
		return m_Count;
	}
	
	
	/**
	 * @brief Sets value at index.
	 */
	inline void set(int index, const TYPE& value)
	{
		assert(index >= 0 && index < m_Count);
		m_Values[index] = value;
	}
	
	
	/**
	 * @brief Gets value at index.
	 */
	inline TYPE& get(int index)
	{
		assert(index >= 0 && index < m_Count);
		return m_Values[index];
	}
	
	
	/**
	 * @brief Gets const value at index.
	 */
	inline const TYPE& get(int index) const
	{
		assert(index >= 0 && index < m_Count);
		return m_Values[index];
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
		for (int i = 0; i < m_Count; i++)
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
		assert(index < m_Count);
		
		resize(m_Count + 1);
		memmove(m_Values + index + 1, m_Values + index,
				sizeof(TYPE) * (m_Count - index - 1));
		new(&m_Values[index]) TYPE(std::forward<Params>(params)...);
		return get(index);
	}
	
	
	/**
	 * @brief Constructs a new value at the end of the Array.
	 * @return reference of the new value.
	 */
	template<typename... Params>
	TYPE& append(Params&&... params)
	{
		int index = m_Count;
		resize(m_Count + 1);
		new(&m_Values[index]) TYPE(std::forward<Params>(params)...);
		return get(m_Count - 1);
	}
	
	
	/**
	 * 
	 */
	int append(const TYPE& value)
	{
		int index = m_Count;
		resize(m_Count + 1);
		new(&m_Values[index]) TYPE(value);
		return index;
	}
	
	
	/**
	 * 
	 */
	void append(const Array<TYPE>& array)
	{
		for (int i = 0; i < array.count(); i++)
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
		assert(0 <= index && index < m_Count);
		
		(&m_Values[index])->~TYPE();
		memmove(m_Values + index, m_Values + index + 1,
				sizeof(TYPE) * (m_Count - index - 1));
		resize(m_Count - 1);
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
		assert((value >= m_Values) && (value < m_Values + sizeof(TYPE) * m_Count));

		value->~TYPE();
		memmove(value, value + sizeof(TYPE),
				(m_Values + sizeof(TYPE) * m_Count) - (value + sizeof(TYPE)));
		resize(m_Count - 1);
	}
	
	
	/**
	 * 
	 */
	void removeAll()
	{
		for (int i = 0; i < m_Count; i++)
			(&m_Values[i])->~TYPE();
		resize(0);
	}
	
	
	/**
	 * 
	 */
	void copy(const Array<TYPE>& array)
	{
		removeAll();
		for (int i = 0; i < array.count(); i++)
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
	TYPE* m_Values;
	int m_Count;
	int m_Reserved;

private:
	/*
	 * Reallocates memory.
	 */
	void resize(int size)
	{
		assert(size >= 0);
		
		if (size > m_Reserved) {
			m_Reserved = size + 16;
			m_Values = (TYPE*) realloc(m_Values, m_Reserved * sizeof(TYPE));
		}
		m_Count = size;
	}
};



#define foreach(value, array)	\
		for(int _i = 0; _i < array.count(); _i++) {	\
			auto value = array[_i];
#define end_foreach()	\
		}


}


#endif
