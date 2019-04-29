#ifndef __G3D__CORE__LINUX__TIMER_HPP__
#define __G3D__CORE__LINUX__TIMER_HPP__

#include <sys/time.h>
#include <Core/Timer.hpp>


namespace g3d {


class Linux_Timer : public Timer
{
public:
	Linux_Timer();
	float elapsed(bool reset);

private:
	struct timeval m_Time;
};


}

#endif