#ifndef __JKIT__CORE__FILE_HPP__
#define __JKIT__CORE__FILE_HPP__

#include <JKit/Core/String.hpp>
#include <JKit/Core/Stream.hpp>


namespace J {


typedef Array<class File> FileList;


class JKIT_PUBLIC_API File
{
public:
//	virtual File parent();
//	virtual File child();
//	virtual FileList listChildren();

	virtual const String& fullPath() const = 0;

	virtual bool isDirectory() const = 0;

	virtual Stream* read() const = 0;
	virtual Stream* write() const = 0;
	virtual Stream* append() const = 0;
};


}

#endif
