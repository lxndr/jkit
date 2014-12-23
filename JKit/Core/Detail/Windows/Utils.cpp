#include <memory>
#include <Core/Windows/Utils.hpp>

namespace J {

WinString::WinString(const String& s)
{
	int count = MultiByteToWideChar(CP_UTF8, 0, s, -1, NULL, 0);
	m_Data = new TCHAR[count];
	MultiByteToWideChar(CP_UTF8, 0, s, -1, m_Data, count);
}


WinString::WinString(int init)
{
	m_Data = new TCHAR[init];
}


WinString::~WinString()
{
	delete[] m_Data;
}


String WinString::conv(LPCTSTR pch)
{
	int count = WideCharToMultiByte(CP_UTF8, 0, pch, -1, NULL, 0, NULL, FALSE);
	std::unique_ptr<char[]> buf(new char[count]);
	WideCharToMultiByte(CP_UTF8, 0, pch, -1, buf.get(), count, NULL, FALSE);
	return String(buf.get());
}


}
