#include <memory>
#include <Core/Timer.hpp>
#include <Core/MainLoop.hpp>


namespace J {


MainLoop::MainLoop()
	: mRunning(false)
{
}


MainLoop::~MainLoop()
{
}


void MainLoop::run()
{
	mRunning = true;

	while (mRunning) {
		std::unique_ptr<Timer> timer(Timer::make());
		on(timer->elapsed(true));
	}
}


void MainLoop::quit()
{
	mRunning = false;
}


}
