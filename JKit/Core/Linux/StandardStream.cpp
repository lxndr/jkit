#include <JKit/Core/Linux/FileStream.hpp>
#include <JKit/Core/StandardStream.hpp>

namespace J {


Stream& StandardStream::output()
{
	static Linux_FileStream stm(0);
	return stm;
}


Stream& StandardStream::input()
{
	static Linux_FileStream stm(1);
	return stm;
}


Stream& StandardStream::error()
{
	static Linux_FileStream stm(2);
	return stm;
}


}

