#include <malloc.h>
#include <string.h>
#include <Core/MemoryStream.hpp>


namespace g3d {


void MemoryStream::resize(size_t length)
{
	if (length == 0) {
		if (mData != nullptr) {
			free(mData);
			mData = nullptr;
			mCurrent = nullptr;
		}
	} else {
		mData = (char*) realloc(mData, length);
		if (!mData)
			throw StreamException("Out of memory");
	}
	
	mSize = length;
}


MemoryStream::MemoryStream(size_t length)
	: mData(nullptr)
{
	resize(length);
	mCurrent = mData;
}


MemoryStream::MemoryStream(char* data, size_t length)
	: mData(nullptr)
{
	resize(length);
	memcpy(mData, data, length);
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


int32_t MemoryStream::read(char* buffer, int32_t count)
{
	memcpy(buffer, mCurrent, count);
	mCurrent += count;
	return true;
}


int32_t MemoryStream::peek(char* buffer, int32_t count)
{
	memcpy(buffer, mCurrent, count);
	return true;
}


int32_t MemoryStream::write(const char* buffer, int32_t count)
{
	if (tell() + count > mSize) {
		mSize = tell() + count;
		mData = (char*) realloc(mData, mSize);
	}
	
	memcpy(mCurrent, buffer, count);
	mCurrent += count;
	return true;
}


}
