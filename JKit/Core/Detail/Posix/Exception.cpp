#include <errno.h>
#include <string.h>
#include <JKit/Core/Exception.hpp>


namespace J {


GenericException::GenericException(const String& reason, bool getError) JKIT_NOEXCEPT
	: m_Reason(reason)
{
	if (getError) {
		m_Code = errno;
		m_Message = strerror(errno);
	} else {
		m_Code = -1;
	}
}


}
