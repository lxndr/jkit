#include <malloc.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>
#include <JKit/Core/String.hpp>


namespace J {


static inline int calcAllocationSize(int size, int pageSize)
{
	size++;
	int pages = size / pageSize;
	if (size % pageSize)
		pages++;
	return pages * pageSize;
}


void String::resize(int length)
{
	int needed = length + 1;
	if (needed > mAllocated) {
		mAllocated = calcAllocationSize(needed, 32);
		mData = (char*) realloc(mData, mAllocated);
	}
	
	mData[length] = 0;
}


String::String()
	: mData(nullptr), mLength(0), mAllocated(-1)
{
	resize(0);
}


String::~String()
{
	free(mData);
#ifndef NDEBUG
	mData = nullptr;
	mLength = 0;
	mAllocated = 0;
#endif
}


String::String(const String& s)
	: mData(nullptr), mLength(0), mAllocated(-1)
{
	assign(s.ptr(), s.length());
}


String::String(const char *pch, int length)
	: mData(nullptr), mLength(0), mAllocated(-1)
{
	assign(pch, length);
}


void String::assign(const char* pch, int length)
{
	assert(pch != nullptr);
	
	mLength = length < 0 ? strlen(pch) : length;
	resize(mLength);
	memcpy (mData, pch, mLength);
}


void String::insert(int pos, const char* pch, int length)
{
	assert(pch != nullptr);
	assert(pos <= mLength);
	
	if (length < 0)
		length = strlen(pch);
	
	resize(mLength + length);
	
	if (pos < mLength)
		memmove(mData + pos + length, mData + pos, mLength - pos);
	
	if (length == 1)
		mData[pos] = *pch;
	else
		memcpy(mData + pos, pch, length);
	
	mLength += length;
}


String String::sub(int start, int count)
{
	assert(start < mLength);
	
	if (count == -1)
		count = mLength - start;
	return String(&mData[start], count);
}


void String::lower()
{
	long n = mLength;
	char *s = mData;
	
	while (n) {
		if (isupper(*s))
			*s = tolower(*s);
		s++;
		n--;
	}
}


bool String::toInteger(int& value)
{
	char* end;
	long int f = strtol(mData, &end, 10);
	if (end == mData || end != mData + mLength)
		return false;
	value = f;
	return true;
}


bool String::toFloat(double& value)
{
	char* end;
	double d = strtod(mData, &end);
	if (end == mData || end != mData + mLength)
		return false;
	value = d;
	return true;
}


String String::format(const char* fmt, ...)
{
	va_list args;
	int len;
	char* buf;
	
	va_start(args, fmt);
#ifdef __USE_GNU

	len = vasprintf(&buf, fmt, args);

#else /* __USE_GNU */

#ifdef _MSC_VER
	#define PRINTF_GETLEN(f, a) _vscprintf(f, a)
	#define PRINTF_N(p, l, f, a) vsnprintf_s(p, l + 1, l, f, a)
#else
	#define PRINTF_GETLEN(f, a) vsnprintf(NULL, 0, f, a)
	#define PRINTF_N(p, l, f, a) vsnprintf(p, l, f, a)
#endif
	len = PRINTF_GETLEN(fmt, args);
	buf = (char*) malloc(len + 1);
	PRINTF_N(buf, len, fmt, args);
	#undef PRINTF_GETLEN
	#undef PRINTF_N

#endif /* __USE_GNU */

	String s(buf, len);
	va_end(args);
	free(buf);
	return s;
}


StringList String::split(const String& delimiter)
{
	StringList list;
	char* p = mData, *f;
	
	while (*p) {
		f = strstr(p, delimiter);
		if (f) {
			list.append(p, f - p);
			p = f + delimiter.length();
		} else {
			list.append(p);
		}
	}
	
	return list;
}


}
