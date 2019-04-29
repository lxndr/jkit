#include <Core/Linux/Dir.hpp>

namespace g3d {


Linux_Dir::Linux_Dir(const String& path)
{
	m_Dir = opendir(path);
//	if (!m_Dir)
//		throw GenericException();
}


Linux_Dir::~Linux_Dir()
{
	closedir(m_Dir);
}


const char* Linux_Dir::next()
{
	struct dirent* ent;
	
	ent = readdir(m_Dir);
	while (ent &&
			(0 == strcmp(ent->d_name, ".") ||
			 0 == strcmp(ent->d_name, "..")))
		ent = readdir(m_Dir);
	
	if (ent)
		return ent->d_name;
	else
		return nullptr;
}


void Linux_Dir::rewind()
{
	rewinddir(m_Dir);
}


Dir* Dir::make(const String& path)
{
	return new Linux_Dir(path);
}


}