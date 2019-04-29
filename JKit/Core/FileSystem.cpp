#include <stdio.h>
#include <sys/stat.h>
//#include <zlib.h>
#include <memory>
#include <JKit/Core/File.hpp>
#include <Core/Dir.hpp>
#include <Core/FileStream.hpp>
#include <Core/MemoryStream.hpp>
#include <Core/FileSystem.hpp>


namespace g3d {


/* real file system directroy */
class G3D_LOCAL_API DirectoryFileSystem : public FileSystem
{
public:
	DirectoryFileSystem(const String& path)
		: m_Path(path)
	{
	}
	
	
	~DirectoryFileSystem()
	{
	}
	
	
	Stream* open(const String& fname)
	{
		return FileStream::makeInput(m_Path + fname);
	}
	
	
	bool list(const String& path, StringList& files)
	{
		try {
			const char* name;
			std::unique_ptr<Dir> dir(Dir::make(m_Path + path));
			while ((name = dir->next()))
				files.append(name);
		} catch (...) {
			return false;
		}
		
		return true;
	}

private:
	String m_Path;
};



/* archive file system */
#if 0
struct ZipHeader {
	uint32_t magic;
	uint16_t version;
	uint16_t flags;
	uint16_t method;
	uint16_t time;
	uint16_t date;
	uint32_t crc;
	uint32_t compSize;
	uint32_t size;
	uint16_t nameLength;
	uint16_t extraFieldLength;
} __attribute__((packed));
#endif


class G3D_LOCAL_API ArchiveFileSystem : public FileSystem
{
public:
	ArchiveFileSystem(const String& path);
	~ArchiveFileSystem();
	
	Stream* open(const String& fname);
	bool list(const String& path, StringList& files);

private:
	struct FileEntity {
		String name;
		uint32_t compSize;
		uint32_t size;
		uint16_t method;
		uint32_t offset;
	};
	
	String mPath;
	Array<FileEntity> mFileList;
	
	FileEntity* find(const String& fname);
};



ArchiveFileSystem::ArchiveFileSystem(const String& path)
	: mPath(path)
{
#if 0
	ZipHeader hdr;
	std::unique_ptr<Stream> stm(FileStream::makeInput(path));
	
	while (stm->read((char*) &hdr, sizeof(hdr))) {
		if (hdr.magic == 0x04034b50) {
			FileEntity& fe = mFileList.append();
			fe.name = stm->readString(hdr.nameLength);
			fe.compSize = hdr.compSize;
			fe.size = hdr.size;
			fe.method = hdr.method;
			
			stm->skip(hdr.extraFieldLength);
			fe.offset = stm->tell();
			stm->skip(hdr.compSize);
		} else {
			break;
		}
	}
#endif
}


ArchiveFileSystem::~ArchiveFileSystem()
{
}


Stream* ArchiveFileSystem::open(const String& fname)
{
#if 0
	FileEntity* fe = find(fname);
	if (!fe)
		return nullptr;
	
	int ret;
	z_stream z;
	memset(&z, 0, sizeof (z));
	if (inflateInit(&z) != Z_OK) {
		printf("error occured while initializing zlib structure\n");
		return nullptr;
	}
	
	std::unique_ptr<FileStream> in(FileStream::makeInput(mPath));
	in->skip(fe->offset);
	MemoryStream* out = new MemoryStream(fe->size);
	Bytef buf[16384];
	
	do {
		z.avail_in = in->read((char*) buf, fe->compSize);
		z.next_in = buf;
		do {
			z.avail_out = out->left();
			z.next_out = (Bytef*) out->cur();
			ret = inflate(&z, Z_NO_FLUSH);
			if (ret != Z_OK || ret != Z_STREAM_END) {
				printf("zlib error occured while reading %s: %s\n",
						(const char*) fname, z.msg);
				inflateEnd(&z);
				delete out;
				return nullptr;
			}
			
			out->skip(16384 - z.avail_out);
		} while (z.avail_out == 0);
	} while (ret != Z_STREAM_END);
	
	inflateEnd(&z);
	return out;
#endif
	return nullptr;
}


bool ArchiveFileSystem::list(const String& path, StringList& files)
{
	for (int i = 0; i < mFileList.getCount(); i++)
		if (strncmp(mFileList[i].name, path, path.length()) == 0)
			files.append(mFileList[i].name);
	
	return true;
}


ArchiveFileSystem::FileEntity* ArchiveFileSystem::find(const String& fname)
{
	for (int i = 0; i < mFileList.getCount(); i++)
		if (mFileList[i].name == fname)
			return &mFileList[i];
	return nullptr;
}



FileSystem::~FileSystem()
{
	for (int i = 0; i < mFileSystemList.getCount(); i++)
		delete mFileSystemList[i];
}


bool FileSystem::mountDirectory(const String& path)
{
	try {
		std::unique_ptr<File> file(File::make(path));
		if (!file->isDirectory())
			throw GenericException("Not a directory", false);
		mFileSystemList.append(new DirectoryFileSystem(path));
	} catch (Exception& e) {
		printf("Failed to mount '%s' as directory\n", (const char*) path);
		printf("\t%s\n", (const char*) e.what());
		return false;
	}
	
	return true;
}


bool FileSystem::mountArchive(const String& path)
{
#if 0
	struct stat st;
	if (stat((const char*) path, &st) == -1) {
		printf("%s\n", strerror(errno));
		return false;
	}
	
	if (!S_ISREG(st.st_mode)) {
		printf("not a directroy\n");
		return false;
	}
	
	mFileSystemList.append(new ArchiveFileSystem(path));
#endif
	return false;
}


Stream* FileSystem::open(const String& fname)
{
	Stream* stm = nullptr;
	
	for (int i = 0; i < mFileSystemList.getCount(); i++)
		if ((stm = mFileSystemList[i]->open(fname)))
			return stm;
	
	return stm;
}


bool FileSystem::list(const String& path, StringList& files)
{
	for (int i = 0; i < mFileSystemList.getCount(); i++)
		mFileSystemList[i]->list(path, files);
	return false;
}


}
