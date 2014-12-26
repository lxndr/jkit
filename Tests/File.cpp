#include <JKit/Core/Exception.hpp>
#include <JKit/Core/LocalFile.hpp>
#include <JKit/Core/Application.hpp>
#include <iostream>


class Application : public J::Application
{
public:
	void startup() {
		stdout->writeLine("Testing basic IO");

		stdout->write("Enter file path: ");
		stdout->flush();

		auto fname = stdin->readLine();
		stdout->writeLine(J::String::format("Opening file '%s'...", fname.ptr()));

		J::LocalFile file(fname);
		auto stm = file.read();
		
	}
};



JKIT_MAIN(Application)
