#include <JKit/Core/Exception.hpp>
#include <JKit/Core/LocalFile.hpp>
#include <iostream>

int main()
{
	try {
		J::LocalFile file("/us");
		file.isDirectory();
	} catch (J::Exception& e) {
		std::cerr << e.what() << std::endl;
	}
	

	return 0;
}
