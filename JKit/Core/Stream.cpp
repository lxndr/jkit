#include <memory>
#include <JKit/Core/Stream.hpp>


namespace J {


StreamException::StreamException(const String& reason) JKIT_NOEXCEPT
	: mReason(reason)
{
}


StreamException::~StreamException() JKIT_NOEXCEPT
{
}


String StreamException::what() const JKIT_NOEXCEPT
{
	return mReason;
}



String Stream::readUntil(char ch)
{
	String s;
	
	for (;;) {
		char c = read<char, 0>();
		if (c == ch || c == 0)
			break;
		s += c;
	}
	
	return s;
}


String Stream::readString(int length)
{
	String s;
	
	if (length == -1) {
		char ch;
		while ((ch = read<char, 0>()))
			s += ch;
	} else if (length > 0) {
		std::unique_ptr<char> p(new char[length]);
		read(p.get(), length);
		return String(p.get(), length);
	}
	
	return s;
}


int64_t Stream::peek(char* buffer, int64_t count) {
	auto ret = read(buffer, count);
	seek(count, SeekType::SeekCurrent);
	return ret;
}


}
