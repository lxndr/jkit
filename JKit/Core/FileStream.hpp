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
	
	virtual void seek(int64_t offset, SeekType type) = 0;
	virtual int64_t tell() const = 0;
	
	virtual int32_t read(char* buffer, int32_t count) = 0;
	virtual int32_t peek(char* buffer, int32_t count) = 0;
	virtual int32_t write(const char* buffer, int32_t count) = 0;
	
	const String& fileName() const
		{return m_FileName;}
	
	static FileStream* makeInput(const String& fname);
	static FileStream* makeOutput(const String& fname, bool append);

private:
	String m_FileName;
};


}


#endif
