#ifndef __JKIT__CORE__WINDOWS__FILE_HPP__
#define __JKIT__CORE__WINDOWS__FILE_HPP__

#include <Core/File.hpp>

namespace J {


class G3D_LOCAL_API Windows_File : public File
{
public:
	Windows_File(const String& path);
	~Windows_File();

	bool isDirectory();

private:
	DWORD m_Attributes;
};


}

#endif
