#include <JKit/Core/Exception.hpp>


namespace J {


GenericException::GenericException(const String& reason, int code, const String& message) JKIT_NOEXCEPT
	: m_Reason(reason), m_Code(code), m_Message(message)
{
}


String GenericException::what() const JKIT_NOEXCEPT
{
	if (m_Code == -1)
		return m_Reason;
	else
		return String::format("%s: (%d) %s", (const char*) m_Reason, m_Code,
				(const char*) m_Message);
}


}
