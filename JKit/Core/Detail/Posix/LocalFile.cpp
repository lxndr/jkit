#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <JKit/Core/Exception.hpp>
#include <JKit/Core/LocalFile.hpp>


namespace J {


struct Context {
	struct stat status;
};


LocalFile::LocalFile(const String& path)
	: File ()
{
	m_Context = new Context;

	if (stat(path, &m_Context->status) == -1)
		throw GenericException("File not found", true);
}


LocalFile::~LocalFile()
{
	delete m_Context;
}


bool LocalFile::isDirectory()
{
	return S_ISDIR(m_Context->status.st_mode);
}


}
