#ifndef __JKIT__CORE__LOCAL_FILE_HPP__
#define __JKIT__CORE__LOCAL_FILE_HPP__

#include <JKit/Core/File.hpp>


namespace J {


class LocalFile : public File {
public:
	LocalFile(const String& path);
	~LocalFile();

	bool isDirectory();

private:
	typedef struct Context* ContextPtr;
	ContextPtr m_Context;
};


}


#endif
