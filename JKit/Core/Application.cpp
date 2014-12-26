#include <JKit/Core/Application.hpp>
#include <JKit/Core/Detail/Posix/FileStream.hpp>
#include <unistd.h>


namespace J {

Application::Application() {
	stdin = new PosixFileStream(STDIN_FILENO, false);
	stdout = new PosixFileStream(STDOUT_FILENO, false);
	stderr = new PosixFileStream(STDERR_FILENO, false);
}


Application::~Application() {
	
}


int Application::run(int argc, char** argv) {
	startup();
}


void Application::startup() {
}


void Application::commandLine(const StringList& args) {
}

}
