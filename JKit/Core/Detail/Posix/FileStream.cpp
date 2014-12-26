#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <JKit/Core/Detail/Posix/FileStream.hpp>


namespace J {


PosixFileStream::PosixFileStream(const String& fname)
	: FileStream(fname)
{
	m_File = ::open((const char*) fname, O_RDONLY, S_IRUSR|S_IWUSR|S_IRGRP);
	if (m_File == -1)
		throw FileStreamException("Failed to open file", fname);
}


PosixFileStream::PosixFileStream(const String& fname, bool append)
	: FileStream(fname)
{
	int flags = O_CREAT|O_WRONLY;
	flags |= append ? O_APPEND : O_TRUNC;
	m_File = ::open((const char*) fname, flags, S_IRUSR|S_IWUSR|S_IRGRP);
	if (m_File == -1)
		throw FileStreamException("Failed to open file", fname);
}


PosixFileStream::PosixFileStream(int fileno, bool close)
	: FileStream(String::format("/proc/self/fd/%d", fileno)),
		m_File(fileno), m_Close(close)
{
}


PosixFileStream::~PosixFileStream()
{
	if (m_Close) {
		/* TODO: you can't just close a file and not process an error */
		close(m_File);
	}
}


void PosixFileStream::seek(int64_t offset, SeekType type)
{
	lseek(m_File, offset, type);
}


int64_t PosixFileStream::tell() const
{
	off64_t pos = lseek64(m_File, 0, SEEK_CUR);
	if (pos == (off64_t) -1)
		return 0;
	return pos;
}


int32_t PosixFileStream::read(char* buffer, int32_t count)
{
	ssize_t ret = ::read(m_File, buffer, count);
	if (ret == -1)
		throw FileStreamException("Failed to read file", fileName());
	return ret;
}


int32_t PosixFileStream::peek(char* buffer, int32_t count)
{
	ssize_t ret = ::read(m_File, buffer, count);
	if (ret == -1)
		throw FileStreamException("Failed to read file", fileName());
	lseek(m_File, -ret, SEEK_CUR);
	return ret;
}


int32_t PosixFileStream::write(const char* buffer, int32_t length)
{
	ssize_t ret = ::write(m_File, buffer, length);
	if (ret == -1)
		throw FileStreamException("Failed to write file", fileName());
	return ret;
}


void PosixFileStream::flush() const
{
	fdatasync(m_File);
}


}
