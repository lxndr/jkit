#include <Core/Windows/Timer.hpp>

namespace g3d {


Windows_Timer::Windows_Timer()
{
	QueryPerformanceFrequency(&m_Frequency);
	QueryPerformanceCounter(&m_Time);
}


float Windows_Timer::elapsed(bool reset)
{
	LARGE_INTEGER now;
	QueryPerformanceCounter(&now);
	float delta = (now.QuadPart - m_Time.QuadPart) *
			1.0e-6f / m_Frequency.QuadPart;
	if (reset)
		m_Time.QuadPart = now.QuadPart;
	return delta;
}


Timer* Timer::make()
{
	return new Windows_Timer;
}


}
