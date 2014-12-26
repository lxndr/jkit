#ifndef __JKIT__CORE__STREAM_HPP__
#define __JKIT__CORE__STREAM_HPP__

#include <JKit/Core/Exception.hpp>
#include <JKit/Core/Platform.hpp>
#include <JKit/Core/String.hpp>


namespace J {


class JKIT_PUBLIC_API StreamException : public Exception
{
public:
	StreamException(const String& reason) JKIT_NOEXCEPT;
	~StreamException() JKIT_NOEXCEPT;
	virtual String what() const JKIT_NOEXCEPT;
	
	const String& reason() const
		{return mReason;}

private:
	String mReason;
};


enum SeekType {
	SeekSet,
	SeekCurrent,
	SeekEnd
};


class JKIT_PUBLIC_API Stream
{
public:
	virtual ~Stream()
		{}
	
	
	/**
	 * 
	 */
	virtual void seek(int64_t offset, SeekType type) = 0;
	
	
	/**
	 * 
	 */
	inline void skip(int64_t offset)
		{seek(offset, SeekCurrent);}
	
	
	/**
	 * 
	 */
	virtual int64_t tell() const = 0;
	
	
	/**
	 * 
	 */
	virtual int32_t peek(char* buffer, int32_t count) = 0;
	
	
	/**
	 * 
	 */
	template<typename TYPE, TYPE DEFAULT>
	inline TYPE peek()
	{
		TYPE value;
		return peek((char*) &value, sizeof(TYPE)) == sizeof(TYPE) ? value : DEFAULT;
	}
	
	
	/**
	 * 
	 */
	virtual int32_t read(char* buffer, int32_t count) = 0;
	
	
	/**
	 * Reads data from the Stream of size of TYPE.
	 * @tparam TYPE the type and length of data to read
	 * @tparam DEFAULT the deafault value to return if reading is failed
	 * @return the read value of type of TYPE
	 */
	template<typename TYPE, TYPE DEFAULT>
	inline TYPE read()
	{
		TYPE value;
		return read((char*) &value, sizeof(TYPE)) == sizeof(TYPE) ? value : DEFAULT;
	}
	
	/**
	 * Reads data from the Stream to val.
	 * @tparam TYPE the type and length of data to read
	 * @param val the variable to read to. Obviously val has to be the type of TYPE
	 * @return true if reading is successful
	 */
	template<typename TYPE>
	inline bool read(TYPE* val)
		{return read((char*) val, sizeof(TYPE)) == sizeof(TYPE);}
	
	
	/**
	 * @brief Reads a String until char occures.
	 */
	String readUntil(char ch);
	
	
	/**
	 * @brief Reads a String.
	 */
	String readString(int length = -1);


	/**
	 * 
	 */
	inline String readLine()
		{ return readUntil('\n'); }
	
	
	/**
	 * 
	 */
	virtual int32_t write(const char* buffer, int32_t count) = 0;
	
	
	/**
	 * Writes a value into the Stream.
	 * @tparam TYPE the type and length of data to write
	 * @param value the pointer of value to write
	 * @return true if writing is succeeded
	 */
	template<typename TYPE>
	inline bool write(const TYPE& value)
	{
		return write((char*) &value, sizeof(TYPE)) == sizeof(TYPE);
	}
	
	
	/**
	 * 
	 */
	inline bool write(const String& s)
	{
		return write(s.ptr(), s.length()) == s.length();
	}


	/**
	 *
	 */
	inline bool writeLine(const String& s)
	{
		return write(s.ptr(), s.length()) == s.length() &&
			write(JKIT_NEW_LINE, sizeof(JKIT_NEW_LINE)) == 1;
	}


	/**
	 *
	 */
	virtual void flush() const {};
};


}


#endif
