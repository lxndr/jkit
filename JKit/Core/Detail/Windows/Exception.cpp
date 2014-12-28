#include <JKit/Core/Detail/Windows/Utils.hpp>
#include <JKit/Core/Exception.hpp>


namespace J {


GenericException::GenericException(const String& reason, bool getError) JKIT_NOEXCEPT
	: m_Reason(reason)
{
	if (!getError) {
		m_Code = -1;
		return;
	}

	LPTSTR lpMsgBuf;
	m_Code = GetLastError();
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS, NULL, m_Code,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR) &lpMsgBuf, 0, NULL);
	m_Message = WinString::conv(lpMsgBuf);
	LocalFree(lpMsgBuf);
}


}
