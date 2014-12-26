#ifndef __JKIT__CORE__APPLICATION_HPP__
#define __JKIT__CORE__APPLICATION_HPP__

#include <JKit/Core/String.hpp>
#include <JKit/Core/Stream.hpp>


namespace J {


class Application
{
public:
	Application();
	virtual ~Application();
	int run(int argc, char** argv);
	virtual void startup();
	virtual void commandLine(const StringList& args);

public:
	Stream* stdin;
	Stream* stdout;
	Stream* stderr;
};


}


#ifdef JKIT_PLATFORM_LINUX

#define JKIT_MAIN(app_class)			\
	int main(int argc, char** argv) {	\
		try {							\
			app_class app;				\
			return app.run(argc, argv);	\
		} catch (std::exception& e) {	\
			std::cerr << "Exception: " << e.what() << std::endl; \
		}								\
	}

#endif


#endif
