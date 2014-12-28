#ifndef __JKIT__CORE__WINDOWS__UTILS_HPP__
#define __JKIT__CORE__WINDOWS__UTILS_HPP__

#include <JKit/Core/String.hpp>


namespace J {

class WinString
{
public:
	WinString(const String& s);
	WinString(int init);
	~WinString();

	inline operator LPTSTR()
		{return m_Data;}
	inline operator LPCTSTR() const
		{return m_Data;}
	inline operator String() const
		{return conv(m_Data);}

	static String conv(LPCTSTR pch);

private:
	PTCHAR m_Data;
};

}


#endif
