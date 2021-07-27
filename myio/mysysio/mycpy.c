#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


//#define BUFFERSIZE 1024

int main(int argc, char **argv)
{
    long long BUFFERSIZE;
    BUFFERSIZE = atoll(argv[3]);
    
    int sfd, dfd;
    int pos;
    ssize_t len, ret;
    char buff[BUFFERSIZE];

    exit(1);
    if(argc < 4)
    {
        fprintf(stderr, "Usage:..\n");
        exit(1);
    }

       sfd = open(argv[1], O_RDONLY);
    
    if(sfd == -1)
    {
        perror("open() failed!");
        exit(1);
    }

    dfd =  open(argv[2], O_WRONLY|O_CREAT, 0666);

    if(dfd == -1)
    {
        close(sfd);
        perror("open() failed!");
        exit(1);
    }

    while(1)
    {
        len = read(sfd, buff, BUFFERSIZE);
        if(len < 0)
        {
            perror("read() failed!");
            break;
        }
        if(len == 0)
            break;
        pos = 0;
        while(len > 0)
        {
            ret = write(dfd, buff+pos, len);  
            if(ret < 0)
            {
                close(dfd);
                close(sfd);
                perror("write() failed!");
                exit(1);
            }
            len -= ret;
            pos += ret;
        }
    }
    close(dfd);
    close(sfd);


    exit(0);
}

