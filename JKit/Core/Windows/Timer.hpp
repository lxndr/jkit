#ifndef __G3D__WINAPI__TIMER_HPP__
#define __G3D__WINAPI__TIMER_HPP__

#include <windows.h>
#include <Core/Timer.hpp>

namespace g3d {


class Windows_Timer : public Timer
{
public:
	Windows_Timer();
	float elapsed(bool reset);

private:
	LARGE_INTEGER m_Frequency;
	LARGE_INTEGER m_Time;
};


}

#endif