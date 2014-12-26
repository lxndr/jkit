#ifndef __JKIT__FILE_STREAM_HPP__
#define __JKIT__FILE_STREAM_HPP__

#include <JKit/Core/Platform.hpp>
#include <JKit/Core/String.hpp>
#include <JKit/Core/Stream.hpp>


namespace J {


class JKIT_PUBLIC_API FileStreamException : public GenericException
{
public:
	FileStreamException(const String& reason, const String& fname) JKIT_NOEXCEPT;
//	~FileStreamException() JKIT_NOEXCEPT;
	
	inline const String& fileName() const JKIT_NOEXCEPT
		{return m_FileName;}

	String what() const JKIT_NOEXCEPT;

private:
	String m_FileName;
};



/**
 *     
 */
class JKIT_PUBLIC_API FileStream : public Stream
{
public:
	FileStream(const String& fname);
	
	const String& fileName() const
		{return m_FileName;}

private:
	String m_FileName;
};


}


#endif
