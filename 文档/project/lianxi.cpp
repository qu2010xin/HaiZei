#include <stdio.h>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
using namespace std;
#define S_ISREG(mode) (((mode) & S_IFMT)==S_IFREG) //S_IS... 原型
int main(int argc,char *argv[])
{
    struct stat buf;

	for(int i=0;i<argc;i++)
	{
        printf("%s: ",argv[i]);
        if(lstat(argv[i],&buf)>=0)
        {
           if(S_ISREG(buf.st_mode))
            {
                cout<<" REG";
            }
           if(S_ISDIR(buf.st_mode))
            {
                cout<<" DIR";
            }
            if(S_ISCHR(buf.st_mode))
            {
                cout<<" CHR";
            }
           if(S_ISBLK(buf.st_mode))
            {
                cout<<" BLK";
            }
           if(S_ISFIFO(buf.st_mode))
            {
                cout<<" FIFO";
            }
            if(S_ISLNK(buf.st_mode))
            {
                cout<<" LINK";
            }
           if(S_ISSOCK(buf.st_mode))
            {
                cout<<" SOCK";
            }
        }
        cout<<endl;
    }
    
 
}