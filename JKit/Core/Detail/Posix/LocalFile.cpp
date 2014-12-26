#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <JKit/Core/Exception.hpp>
#include <JKit/Core/LocalFile.hpp>
#include <JKit/Core/Detail/Posix/FileStream.hpp>


namespace J {


struct Context {
	struct stat status;
};


LocalFile::LocalFile(const String& path)
	: m_FullPath(path)
{
	m_Context = new Context;

	if (stat(path, &m_Context->status) == -1)
		throw GenericException("File not found", true);
}


LocalFile::~LocalFile()
{
	delete m_Context;
}


bool LocalFile::isDirectory() const
{
	return S_ISDIR(m_Context->status.st_mode);
}


Stream* LocalFile::read() const
{
	return new PosixFileStream(fullPath());
}


Stream* LocalFile::write() const
{
	return new PosixFileStream(fullPath(), false);
}


Stream* LocalFile::append() const
{
	return new PosixFileStream(fullPath(), true);
}


}
