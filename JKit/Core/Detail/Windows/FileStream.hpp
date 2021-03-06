#ifndef __JKIT__CORE__WINDOWS__FILE_STREAM_HPP__
#define __JKIT__CORE__WINDOWS__FILE_STREAM_HPP__

#include <JKit/Core/FileStream.hpp>

namespace J {

class JKIT_LOCAL_API Windows_FileStream : public FileStream
{
public:
	Windows_FileStream(const String& fname);
	Windows_FileStream(const String& fname, bool append);
	~Windows_FileStream();
	
	void seek(int64_t offset, SeekType type);
	int64_t tell() const;
	
	int32_t read(char* buffer, int32_t count);
	int32_t peek(char* buffer, int32_t count);
	int32_t write(const char* buffer, int32_t count);

private:
	HANDLE m_File;
};

}

#endif