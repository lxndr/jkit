#include <Core/Exception.hpp>
#include <Core/Windows/Utils.hpp>
#include <Core/Windows/Dir.hpp>

namespace g3d {


Windows_Dir::Windows_Dir(const String& path)
	: m_Path(path), m_First(true)
{
	m_Find = FindFirstFile(WinString(path), &m_FindData);
	if (m_Find == INVALID_HANDLE_VALUE)
		throw GenericException("Not found", true);
}


Windows_Dir::~Windows_Dir()
{
	FindClose(m_Find);
}


const char* Windows_Dir::next()
{
	if (m_First) {
		m_First = false;
	} else {
		if (!FindNextFile(m_Find, &m_FindData) && GetLastError() == ERROR_NO_MORE_FILES)
			return nullptr;
	}
	
//	WinString wname(m_FindData.cFileName);
//	m_FileName = wname;
//	return m_FileName.ptr();
	return (const char*) m_FindData.cFileName;
}


void Windows_Dir::rewind()
{
	if (m_Find)
		FindClose(m_Find);
	m_Find = FindFirstFile(WinString(m_Path), &m_FindData);
	m_First = true;
}


Dir* Dir::make(const String& path)
{
	return new Windows_Dir(path);
}


}