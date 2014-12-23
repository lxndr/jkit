#include <JKit/Core/StandardStream.hpp>


int main() {
	J::Stream& cout = J::StandardStream::output();
	J::Stream& cin = J::StandardStream::input ();

	cout.write("Hello, World!\n");
//	J::String answer = cin.read("Question?: ");
	cout.write(J::String::format("Answer: %d\n", 6));

	return 0;
}
