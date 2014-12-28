#ifndef __JKIT__CORE__MEMORY_STREAM_HPP__
#define __JKIT__CORE__MEMORY_STREAM_HPP__

#include <JKit/Core/Stream.hpp>


namespace J {


class JKIT_PUBLIC_API MemoryStream : public Stream
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
	MemoryStream(int64_t length);
	
	
	/**
	 *
	 */
	MemoryStream(char* data, int64_t length);
	
	
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
	int64_t read(char* buffer, int64_t count);
	
	
	/**
	 * 
	 */
	int64_t peek(char* buffer, int64_t count);
	
	
	/**
	 * 
	 */
	int64_t write(const char* buffer, int64_t count);
	
	
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
	int64_t mSize;
	
	void resize(int64_t length);
};


}

#endif
