#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>



int main(int argc, char **argv)
{
    int fd;

    if(argc < 2)
    {
        fprintf(stderr, "Usage:...\n");
        exit(1);
    }
    
    fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0666);

    lseek(fd,5LL*1024LL*1024LL*1024LL-1LL , SEEK_SET);

    //printf("%d\n",write(fd, "\0",1));    


    close(fd);

    return 0;
}

