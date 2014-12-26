#include <JKit/Core/Application.hpp>


namespace J {

Application::Application() {
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
