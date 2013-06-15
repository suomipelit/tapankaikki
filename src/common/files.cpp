#include "files.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

const std::string SaveDataPath = "./";
const std::string DATADIR = ".";


EXPORT std::string getsavepath(const std::string& name)
{
	std::string ret = SaveDataPath + name;
#ifdef _DEBUG
	printf("Savepath: %s\n", ret.c_str());
#endif
	return ret;
}

EXPORT std::string getdatapath(const std::string& name)
{
	std::string ret = std::string(DATADIR) + std::string("/") + name;
#ifdef _DEBUG
	printf("Datapath: %s\n", ret.c_str());
#endif
	return ret;
}

EXPORT std::string getpath(const char *name)
{
	int len = strlen(name);
	int a=0;
	std::string ret;
	for (a=len-1;a>0 && name[a]!='/' && name[a]!='\\';a--) {};
	if (a>0)
	for (int b=0;b<=a;b++)
		ret+=name[b];
	return (ret);
}

EXPORT int exists(const char *name)
{
    FILE *f;
    f=fopen(name,"rb");
    if (f==NULL) return(0);
    fclose(f);
    return(1);
}

EXPORT int filelen(const char *name)
{
    FILE *f;
    int len;
    f=fopen(name,"rb");
    if (f==NULL) return(-1);
    fseek(f,0,SEEK_END);
    len=ftell(f);
    fclose(f);
    return(len);
}

EXPORT int filetimestamp(const char *name)
{
	struct _stat fileinfo;

	if (_stat(name,&fileinfo)==-1) return -1;

	return fileinfo.st_mtime;
}
