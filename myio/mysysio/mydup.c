#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>


#define FNAME "/tmp/out"


int main()
{
    int fd;
    close(1);
    fd = open(FNAME,O_WRONLY|O_CREAT|O_TRUNC, 0666);
    
    if(fd == -1)
    {
        perror("open()");
        exit(1);
    }

    dup2(fd, 1);
    if(fd != 1)
        close(fd);

   /******************/ 
    puts("Hello!");

    //应该加一句还原原来的环境

    exit(0);
}

