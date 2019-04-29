#ifndef __G3D__CORE__DIR_HPP__
#define __G3D__CORE__DIR_HPP__

#include <Core/String.hpp>


namespace g3d {


class Dir
{
public:
	virtual const char* next() = 0;
	virtual void rewind() = 0;
	
	static Dir* make(const String& path);
};


}

#endif