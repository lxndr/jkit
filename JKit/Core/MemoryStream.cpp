#include <malloc.h>
#include <string.h>
#include <JKit/Core/MemoryStream.hpp>


namespace J {


void MemoryStream::resize(int64_t length)
{
	if (length == 0) {
		if (mData != nullptr) {
			free(mData);
			mData = nullptr;
			mCurrent = nullptr;
		}
	} else {
		mData = (char*) realloc(mData, (size_t) length);
		if (!mData)
			throw StreamException("Out of memory");
	}
	
	mSize = length;
}


MemoryStream::MemoryStream(int64_t length)
	: mData(nullptr)
{
	resize(length);
	mCurrent = mData;
}


MemoryStream::MemoryStream(char* data, int64_t length)
	: mData(nullptr)
{
	resize(length);
	memcpy(mData, data, (size_t) length);
	mCurrent = mData;
}


MemoryStream::~MemoryStream()
{
	resize(0);
}


void MemoryStream::seek(int64_t offset, SeekType type)
{
	switch (type) {
	case SeekSet:
		if (offset >= 0)
			mCurrent = mData + offset;
		break;
	case SeekCurrent:
		if (offset > 0) {
			mCurrent += offset;
		} else {
			if (offset <= tell())
				mCurrent -= offset;
			else
				mCurrent = mData;
		}
		break;
	case SeekEnd:
		mCurrent = mData + mSize + offset;
		break;
	}
}


int64_t MemoryStream::tell() const
{
	return mData ? mCurrent - mData : -1;
}


int64_t MemoryStream::read(char* buffer, int64_t count)
{
	memcpy(buffer, mCurrent, (size_t) count);
	mCurrent += count;
	return true;
}


int64_t MemoryStream::peek(char* buffer, int64_t count)
{
	memcpy(buffer, mCurrent, (size_t) count);
	return true;
}


int64_t MemoryStream::write(const char* buffer, int64_t count)
{
	if (tell() + count > mSize) {
		mSize = tell() + count;
		mData = (char*) realloc(mData, (size_t) mSize);
	}
	
	memcpy(mCurrent, buffer, (size_t) count);
	mCurrent += count;
	return true;
}


}
