#ifndef __G3D__CORE__WINDOWS__DIR_HPP__
#define __G3D__CORE__WINDOWS__DIR_HPP__

#include <Core/Platform.hpp>
#include <Core/Dir.hpp>


namespace g3d {


class Windows_Dir : public Dir
{
public:
	Windows_Dir(const String& path);
	~Windows_Dir();
	
	const char* next();
	void rewind();

private:
	HANDLE m_Find;
	WIN32_FIND_DATA m_FindData;
	String m_Path;
	String m_FileName;
	bool m_First;
};


}

#endif