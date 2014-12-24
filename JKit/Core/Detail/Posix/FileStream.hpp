#ifndef __JKIT__CORE__LINUX__FILE_STREAM_HPP__
#define __JKIT__CORE__LINUX__FILE_STREAM_HPP__

#include <JKit/Core/FileStream.hpp>


namespace J {


class G3D_LOCAL_API Linux_FileStream : public FileStream
{
public:
	Linux_FileStream(const String& fname);
	Linux_FileStream(const String& fname, bool append);
	Linux_FileStream(int fileno);
	~Linux_FileStream();
	
	void seek(int64_t offset, SeekType type);
	int64_t tell() const;
	
	int32_t read(char* buffer, int32_t count);
	int32_t peek(char* buffer, int32_t count);
	int32_t write(const char* buffer, int32_t count);

private:
	int m_File;
};


}


#endif
