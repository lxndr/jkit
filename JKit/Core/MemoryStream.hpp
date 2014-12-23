#ifndef __MEMORY_STREAM_HPP__
#define __MEMORY_STREAM_HPP__

#include <Core/Stream.hpp>


namespace g3d {


class G3D_PUBLIC_API MemoryStream : public Stream
{
public:
	/**
	 * 
	 */
	inline MemoryStream()
		: MemoryStream(nullptr, 0)
		{}
	
	
	/**
	 * 
	 */
	MemoryStream(size_t length);
	
	
	/**
	 *
	 */
	MemoryStream(char* data, size_t length);
	
	
	/**
	 * 
	 */
	~MemoryStream();
	
	
	/**
	 * 
	 */
	void seek(int64_t offset, SeekType type);
	
	
	/**
	 * 
	 */
	int64_t tell() const;
	
	
	/**
	 * 
	 */
	int32_t read(char* buffer, int32_t count);
	
	
	/**
	 * 
	 */
	int32_t peek(char* buffer, int32_t count);
	
	
	/**
	 * 
	 */
	int32_t write(const char* buffer, int32_t count);
	
	
	/**
	 * 
	 */
	inline char* ptr()
		{return mData;}
	
	
	/**
	 * 
	 */
	inline char* cur()
		{return mCurrent;}
	
	
	/**
	 * 
	 */
	inline int64_t left()
		{return mSize - tell();}

private:
	char* mData;
	char* mCurrent;
	uint32_t mSize;
	
	void resize(size_t length);
};


}

#endif
