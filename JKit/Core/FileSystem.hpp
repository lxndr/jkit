#ifndef __FILE_SYSTEM_HPP__
#define __FILE_SYSTEM_HPP__

#include <sys/types.h>
#include <Core/Platform.hpp>
#include <Core/FileStream.hpp>


namespace g3d {


class G3D_PUBLIC_API FileSystem
{
public:
	FileSystem() {}
	virtual ~FileSystem();
	
	bool mountDirectory(const String& path);
	bool mountArchive(const String& path);
	
	virtual Stream* open(const String& fname);
	virtual bool list(const String& path, StringList& files);

private:
	Array<FileSystem*> mFileSystemList;
};


}


#endif
