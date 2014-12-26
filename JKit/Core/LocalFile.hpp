#ifndef __JKIT__CORE__LOCAL_FILE_HPP__
#define __JKIT__CORE__LOCAL_FILE_HPP__

#include <JKit/Core/File.hpp>


namespace J {


class LocalFile : public File {
public:
	LocalFile(const String& path);
	~LocalFile();

	bool isDirectory() const;

	const String& fullPath() const
		{ return m_FullPath; }

	Stream* read() const;
	Stream* write() const;
	Stream* append() const;

private:
	typedef struct Context* ContextPtr;
	ContextPtr m_Context;
	String m_FullPath;
};


}


#endif
