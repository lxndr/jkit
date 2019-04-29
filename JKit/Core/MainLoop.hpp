#ifndef __MAIN_LOOP_HPP__
#define __MAIN_LOOP_HPP__

#include <sigc++/signal.h>
#include <Core/Platform.hpp>


namespace J {


class JKIT_PUBLIC_API MainLoop
{
public:
	MainLoop();
	~MainLoop();
	
	void run();
	void quit();
	
	sigc::signal<void, float> on;
	
private:
	bool mRunning;
};


}


#endif
