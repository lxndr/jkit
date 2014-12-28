#include <JKit/Core/Application.hpp>
#include <JKit/Core/Detail/Posix/FileStream.hpp>


namespace J {

Application::Application() {
/*	m_StdIn = new PosixFileStream(STDIN_FILENO, false);
	m_StdOut = new PosixFileStream(STDOUT_FILENO, false);
	m_StdErr = new PosixFileStream(STDERR_FILENO, false); */
}


Application::~Application() {
	
}


int Application::run(int argc, char** argv) {
	startup();
	return 0;
}


void Application::startup() {
}


void Application::commandLine(const StringList& args) {
}

}
