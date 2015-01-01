#ifndef __JKIT__CORE__LINUX__FILE_STREAM_HPP__
#define __JKIT__CORE__LINUX__FILE_STREAM_HPP__

#include <JKit/Core/FileStream.hpp>


namespace J {


class JKIT_LOCAL_API PosixFileStream : public FileStream
{
public:
	PosixFileStream(const String& fname);
	PosixFileStream(const String& fname, bool append);
	PosixFileStream(int fileno, bool close);
	~PosixFileStream();
	
	void seek(int64_t offset, SeekType type);
	int64_t tell() const;
	
	int64_t read(char* buffer, int64_t count);
	int64_t write(const char* buffer, int64_t count);
	void flush() const;

private:
	int m_File;
	bool m_Close;
};


}


#endif
