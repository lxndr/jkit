#include <Core/Exception.hpp>
#include <Core/Windows/Utils.hpp>
#include <Core/Windows/File.hpp>

namespace g3d {


Windows_File::Windows_File(const String& path)
{
	m_Attributes = GetFileAttributes(WinString(path));
	if (m_Attributes == INVALID_FILE_ATTRIBUTES)
		throw GenericException("File not found", true);
}


Windows_File::~Windows_File()
{
}


File* File::make(const String& path)
{
	return new Windows_File(path);
}


bool Windows_File::isDirectory()
{
	return (m_Attributes & FILE_ATTRIBUTE_DIRECTORY) > 0;
}


}