#include <JKit/Core/FileStream.hpp>


namespace J {


FileStreamException::FileStreamException(const String& reason, const String& fname) JKIT_NOEXCEPT
	: GenericException(reason, true), m_FileName(fname)
{
}


//FileStreamException::~FileStreamException() G3D_NOEXCEPT
//{
//}


String FileStreamException::what() const JKIT_NOEXCEPT
{
	return String::format("%s '%s': (%d) %s\n", (const char*) reason(),
			(const char*) fileName(), code(), (const char*) message());
}


FileStream::FileStream(const String& fname)
	: m_FileName(fname)
{
}


}
