#ifndef __JKIT__STANDARD_STREAM_HPP__
#define __JKIT__STANDARD_STREAM_HPP__

#include <JKit/Core/Stream.hpp>

namespace J {


class StandardStream
{
public:
	static Stream& output();
	static Stream& input();
	static Stream& error();
};


}

#endif
