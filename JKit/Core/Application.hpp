#ifndef __JKIT__CORE__APPLICATION_HPP__
#define __JKIT__CORE__APPLICATION_HPP__

#include <JKit/Core/String.hpp>


namespace J {


class Application
{
public:
	Application();
	virtual ~Application();
	int run(int argc, char** argv);
	virtual void startup();
	virtual void commandLine(const StringList& args);
};


}


#ifdef JKIT_PLATFORM_LINUX

/**
 * 
 */
#define JKIT_MAIN(app_class)			\
	int main(int argc, char** argv) {	\
		app_class app;					\
		return app.run(argc, argv);		\
	}

#endif


#endif
