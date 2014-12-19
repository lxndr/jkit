#ifndef __JKIT__STRING_HPP__
#define __JKIT__STRING_HPP__

#include <stdlib.h>
#include <JKit/Core/Platform.hpp>
#include <JKit/Core/Array.hpp>


namespace J {


class StringRef;
typedef Array<class String> StringList;


class JKIT_PUBLIC_API String
{
public:
	/**
	 * @brief Constructs an empty String.
	 */
	String();
	
	
	/**
	 * @brief Constructs a copy of s.
	 */
	String(const String& s);
	
	
	/**
	 * 
	 */
	String(const char *pch, int length = -1);
	
	
	/**
	 * 
	 */
	~String();
	
	
	/**
	 * @brief Gets size of the string in bytes.
	 */
	inline int length() const
		{return mLength;}
	
	
	/**
	 * @brief Tests if the String is empty.
	 */
	inline bool isEmpty() const
		{return mLength == 0;}
	
	
	/**
	 * 
	 */
	inline const char* ptr() const
		{return mData;}
	
	
	/**
	 * 
	 */
	inline operator const char*() const
		{return mData;}
	

	/**
	 * 
	 */
	inline void set(int index, char ch)
		{mData[index] = ch;}
	
	
	/**
	 * 
	 */
	inline char get(int index) const
		{return mData[index];}
	
	
	/**
	 * 
	 */
	inline char operator[](int index) const
		{return mData[index];}
	
	
	/**
	 * 
	 */
	uint32_t getChar(int index) const;
	
	
	/**
	 * 
	 */
	inline void empty()
		{mLength = 0; resize(0);}
	
	
	/**
	 * 
	 */
	void assign(const char* pch, int length = -1);
	
	
	/**
	 * 
	 */
	inline void assign(const String& s)
		{assign(s.mData, s.mLength);}
	
	
	/**
	 * Because length is provided, pch may contain embedded nuls and
	 *   need not be nul-terminated.
	 * @brief Inserts length bytes of pch into the String at pos.
	 * @param length if negative, strlen calculates the length
	 */
	void insert(int pos, const char* pch, int length = -1);
	
	
	/**
	 * @brief Adds a byte onto the end of the String.
	 */
	inline void append(char ch)
		{append(&ch, 1);}
	
	
	/**
	 * @brief Adds a string onto the end of the String.
	 * @param pch null-teriminated pointer
	 * @param count number of bytes to append
	 */
	inline void append(const char *pch, int length = -1)
		{insert(mLength, pch, length);}
	
	
	/**
	 * @brief Adds a String onto the end of the String.
	 */
	inline void append(const String& str)
		{append(str.mData, str.mLength);}
	
	
	/**
	 * 
	 */
	inline void prepend(char ch)
		{prepend(&ch, 1);}
	
	
	/**
	 * 
	 */
	inline void prepend(const char* pch, int length = -1)
		{insert(0, pch, length);}
	
	
	/**
	 * 
	 */
	inline void prepend(const String& str)
		{prepend(str.mData, str.mLength);}
	
	
	/**
	 * 
	 */
	inline void operator=(const char* pch)
		{assign(pch, -1);}
	
	
	/**
	 * 
	 */
	inline void operator=(const String& s)
		{assign(s.mData, s.mLength);}
	
	
	/**
	 * 
	 */
	inline void operator+=(char ch)
		{append(ch);}
	
	
	/**
	 * 
	 */
	inline void operator+=(const char *pch)
		{append(pch, -1);}
	
	
	/**
	 * 
	 */
	inline void operator+=(const String& str)
		{append(str);}
	
	
	/**
	 * 
	 */
	inline String operator+(const String& str)
		{String s(mData, mLength); s.append(str); return s;}
	
	
	/**
	 * 
	 */
	inline String operator+(char ch)
		{String s(mData, mLength); s.append(ch); return s;}
	
	
	/**
	 * 
	 */
	friend inline String operator+(const char* pch, const String& str)
		{return String(pch) + str;}
	
	
	inline bool comp(const char* pch, int count)
		{return strncmp(mData, pch, count) == 0;}
	
	
	/**
	 * 
	 */
	inline bool operator==(const char* pch) const
		{return strcmp(mData, pch) == 0;}
	
	
	/**
	 * 
	 */
	inline bool operator==(const String& str) const
		{return mLength == str.mLength && memcmp(mData, str, mLength) == 0;}
	
	
	/**
	 * 
	 */
	String sub(int start, int count);
	
	
	void lower();
	
	/**
	 * @brief Converts the String to an integer.
	 */
	inline int toInteger()
		{return atol(mData);}
	
	
	/**
	 * @brief Converts the String to an integer.
	 */
	bool toInteger(int& value);
	
	
	/**
	 * @brief Converts the String to a float.
	 */
	inline double toFloat()
		{return atof(mData);}
	
	
	/**
	 * 
	 */
	bool toFloat(double& value);
	
	
	/**
	 * It behaves exactly like sprintf, but allocates needed memory.
	 * @brief Constructs a new String using formatting rules.
	 */
	static String format(const char* fmt, ...) JKIT_PRINTF(1, 2);
	
	
	/**
	 * 
	 */
	StringList split(const String& delimiter);

private:
	char *mData;
	int mLength;
	int mAllocated;
	
	void resize(int size);
};



class JKIT_PUBLIC_API StringRef
{
public:
	StringRef(const String& str, int start, int length = -1)
		: mString(str), mStart(start), mLength(length)
	{}
	
	
	inline StringRef(const StringRef& ref)
		: mString(ref.mString), mStart(ref.mStart), mLength(ref.mLength)
	{}
	
	
	inline ~StringRef()
	{}
	
	
	inline bool operator==(const String& str)
	{
		return strncmp(str, mString.ptr() + mStart, mLength) == 0;
	}
	
	
	inline bool operator!=(const String& str)
	{
		return strncmp(str, mString.ptr() + mStart, mLength) != 0;
	}
	
private:
	const String& mString;
	int mStart;
	int mLength;
};


}


#endif
