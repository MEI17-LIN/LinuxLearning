#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

static int ftype(const char *fname)
{
	struct stat st;

	if(stat(fname, &st) == -1)
	{
		perror("stat()");
		exit(1);
	}

	switch(st.st_mode & S_IFMT)
	{
		case S_IFREG:
			return '-';
			break;
		case S_IFDIR:
			return 'd';
			break;
		case S_IFSOCK:
			return 's';
			break;
		default:
			return '?';

	}


}



int main(int argc, char **argv)
{
	if(argc < 2)
	{
		fprintf(stderr, "Usage..\n");
		exit(1);
	}

	printf("%s is a %c file.\n", argv[1], ftype(argv[1]));


	exit(0);
}
