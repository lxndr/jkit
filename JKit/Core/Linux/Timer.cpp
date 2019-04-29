#include <Core/Linux/Timer.hpp>

namespace g3d {


Linux_Timer::Linux_Timer()
{
	gettimeofday(&m_Time, nullptr);
}


float Linux_Timer::elapsed(bool reset)
{
	struct timeval now;
	gettimeofday(&now, nullptr);
	float delta = (float)(now.tv_sec  - m_Time.tv_sec) +
			1.0e-6 * (now.tv_usec - m_Time.tv_usec);
	if (reset)
		m_Time = now;
	return delta;
}


Timer* Timer::make()
{
	return new Linux_Timer;
}


}