#include <JKit/Core/Exception.hpp>
#include <JKit/Core/LocalFile.hpp>
#include <JKit/Core/Detail/Windows/Utils.hpp>


namespace J {


LocalFile::LocalFile(const String& path)
	: m_FullPath(path)
{
}


LocalFile::~LocalFile()
{
}


bool LocalFile::isDirectory() const
{
	DWORD attrs = GetFileAttributes(WinString(m_FullPath));
	if (attrs == INVALID_FILE_ATTRIBUTES)
		throw GenericException("File not found", true);
	return (attrs & FILE_ATTRIBUTE_DIRECTORY) > 0;
}


}