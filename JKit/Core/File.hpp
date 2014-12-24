#ifndef __JKIT__CORE__FILE_HPP__
#define __JKIT__CORE__FILE_HPP__

#include <JKit/Core/String.hpp>


namespace J {


typedef Array<class File> FileList;


class JKIT_PUBLIC_API File
{
public:
//	virtual File parent();
//	virtual File child();
//	virtual FileList listChildren();

	virtual bool isDirectory() = 0;
};


}

#endif
