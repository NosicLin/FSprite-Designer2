#ifndef _DS_FILE_UTIL_H_
#define _DS_FILE_UTIL_H_

class DsFileUtil 
{
	public:
		static QString dirName(const char* path);
        static QString baseName(const char* path);
        static QString toProjectPath(const char* path);
};


#endif /*_FILE_UTIL_H_*/
