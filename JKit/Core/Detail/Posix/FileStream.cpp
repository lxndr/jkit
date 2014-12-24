#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
// #include <JKit/Core/Linux/FileStream.hpp>


namespace J {


Linux_FileStream::Linux_FileStream(const String& fname)
	: FileStream(fname)
{
	m_File = ::open((const char*) fname, O_RDONLY, S_IRUSR|S_IWUSR|S_IRGRP);
	if (m_File == -1)
		throw FileStreamException("Failed to open file", fname);
}


Linux_FileStream::Linux_FileStream(const String& fname, bool append)
	: FileStream(fname)
{
	int flags = O_CREAT|O_WRONLY;
	flags |= append ? O_APPEND : O_TRUNC;
	m_File = ::open((const char*) fname, flags, S_IRUSR|S_IWUSR|S_IRGRP);
	if (m_File == -1)
		throw FileStreamException("Failed to open file", fname);
}


Linux_FileStream::Linux_FileStream(int fileno)
	: FileStream(String::format("/proc/self/fd/%d", fileno))
{
	m_File = fileno;
}


Linux_FileStream::~Linux_FileStream()
{
	close(m_File);
}


void Linux_FileStream::seek(int64_t offset, SeekType type)
{
	lseek(m_File, offset, type);
}


int64_t Linux_FileStream::tell() const
{
	off64_t pos = lseek64(m_File, 0, SEEK_CUR);
	if (pos == (off64_t) -1)
		return 0;
	return pos;
}


int32_t Linux_FileStream::read(char* buffer, int32_t count)
{
	ssize_t ret = ::read(m_File, buffer, count);
	if (ret == -1)
		throw FileStreamException("Failed to read file", fileName());
	return ret;
}


int32_t Linux_FileStream::peek(char* buffer, int32_t count)
{
	ssize_t ret = ::read(m_File, buffer, count);
	if (ret == -1)
		throw FileStreamException("Failed to read file", fileName());
	lseek(m_File, -ret, SEEK_CUR);
	return ret;
}


int32_t Linux_FileStream::write(const char* buffer, int32_t length)
{
	ssize_t ret = ::write(m_File, buffer, length);
	if (ret == -1)
		throw FileStreamException("Failed to write file", fileName());
	return ret;
}


FileStream* FileStream::makeInput(const String& fname)
{
	return new Linux_FileStream(fname);
}


FileStream* FileStream::makeOutput(const String& fname, bool append)
{
	return new Linux_FileStream(fname, append);
}


}
