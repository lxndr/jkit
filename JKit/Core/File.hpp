#ifndef __JKIT__CORE__FILE_HPP__
#define __JKIT__CORE__FILE_HPP__

#include <JKit/Core/String.hpp>


namespace J {


class JKIT_PUBLIC_API File
{
public:
	virtual bool isDirectory() = 0;


private:
};


}

#endif
