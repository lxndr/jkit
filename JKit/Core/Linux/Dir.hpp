#ifndef __G3D__CORE__LINUX__DIRECTORY_HPP__
#define __G3D__CORE__LINUX__DIRECTORY_HPP__

#include <dirent.h>
#include <Core/Dir.hpp>


namespace g3d {


class Linux_Dir : public Dir
{
public:
	Linux_Dir(const String& path);
	~Linux_Dir();
	
	const char* next();
	void rewind();

private:
	DIR* m_Dir;
};


}

#endif