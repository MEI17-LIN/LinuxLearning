/*************************************************************************
    > File Name: mydu.c
    > Author: TL
    > Mail: XXX
    > Created Time: 2021年07月31日 星期六 16时14分17秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>

static int64_t mydu(const char *path)
{
	

}


int main(int argc, char **argv)
{
	if(argc < 2)
	{
		fprintf("stderr", "Usage...\n");
		exit(1);
	}

	printf("%lld\n", mydu(argv[1]));
	exit(0);
}
