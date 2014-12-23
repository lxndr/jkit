#ifndef __JKIT__CORE__EXCEPTION_HPP__
#define __JKIT__CORE__EXCEPTION_HPP__

#include <JKit/Core/Platform.hpp>
#include <JKit/Core/String.hpp>


namespace J {


class JKIT_PUBLIC_API Exception
{
public:
	virtual String what() const JKIT_NOEXCEPT = 0;
};



class JKIT_PUBLIC_API GenericException : public Exception
{
public:
	GenericException(const String& reason, int code, const String& message) JKIT_NOEXCEPT;
	GenericException(const String& reason, bool getError) JKIT_NOEXCEPT;

	inline const String& reason() const JKIT_NOEXCEPT
		{return m_Reason;}
	inline int code() const JKIT_NOEXCEPT
		{return m_Code;}
	inline const String& message() const JKIT_NOEXCEPT
		{return m_Message;}

	virtual String what() const JKIT_NOEXCEPT;

private:
	String m_Reason;
	int m_Code;
	String m_Message;
};


}


#endif
