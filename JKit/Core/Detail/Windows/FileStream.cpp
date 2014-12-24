#include <Core/Windows/Utils.hpp>
#include <Core/Windows/FileStream.hpp>


namespace g3d {


Windows_FileStream::Windows_FileStream(const String& fname)
	: FileStream(fname)
{
	m_File = ::CreateFile(WinString(fname), GENERIC_READ, FILE_SHARE_READ,
			NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (m_File == INVALID_HANDLE_VALUE)
		throw FileStreamException("Failed to open file", fname);
}


Windows_FileStream::Windows_FileStream(const String& fname, bool append)
	: FileStream(fname)
{
	/* first try to truncate file if it exists */
	m_File = ::CreateFile(WinString(fname), GENERIC_WRITE, FILE_SHARE_WRITE,
			NULL, TRUNCATE_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (m_File == INVALID_HANDLE_VALUE && GetLastError() == ERROR_FILE_NOT_FOUND)
		/* then try to create an empty file */
		m_File = ::CreateFile(WinString(fname), GENERIC_WRITE, FILE_SHARE_WRITE,
				NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	
	if (m_File == INVALID_HANDLE_VALUE)
		throw FileStreamException("Failed to open file", fname);
	
	if (append)
		seek(0, SeekEnd);
}


FileStream* FileStream::makeInput(const String& fname)
{
	return new Windows_FileStream(fname);
}


FileStream* FileStream::makeOutput(const String& fname, bool append)
{
	return new Windows_FileStream(fname, append);
}


Windows_FileStream::~Windows_FileStream()
{
	CloseHandle(m_File);
}


void Windows_FileStream::seek(int64_t offset, SeekType type)
{
	LARGE_INTEGER li;
	li.QuadPart = offset;
	li.LowPart = SetFilePointer(m_File, li.LowPart, &li.HighPart, type);
}


int64_t Windows_FileStream::tell() const
{
	LARGE_INTEGER li;
	li.QuadPart = 0;
	li.LowPart = SetFilePointer(m_File, li.LowPart, &li.HighPart, FILE_CURRENT);
	if (li.LowPart == INVALID_SET_FILE_POINTER && GetLastError() != NO_ERROR)
		li.QuadPart = -1;
	return li.QuadPart;
}


int32_t Windows_FileStream::read(char* buffer, int32_t count)
{
	DWORD bytesRead;
	if (!::ReadFile(m_File, buffer, count, &bytesRead, NULL))
		throw FileStreamException("Failed to read to file", fileName());
	return bytesRead;
}


int32_t Windows_FileStream::peek(char* buffer, int32_t count)
{
	int32_t ret = read(buffer, count);
	seek(-ret, SeekCurrent);
	return ret;
}


int32_t Windows_FileStream::write(const char* buffer, int32_t length)
{
	DWORD bytesWritten;
	if (!::WriteFile(m_File, buffer, length, &bytesWritten, NULL))
		throw FileStreamException("Failed to write to file", fileName());
	return bytesWritten;
}


}
