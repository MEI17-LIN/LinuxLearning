#include <stdio.h>
#include <stdlib.h>
#include <glob.h>

#define PAT "/etc/a*.conf"



static int errfunc_(const char *epath, int eerrno)
{
	puts(epath);
	fprintf(stderr, "Error Path:%s\n", epath);
	perror("Error:");
	return -1;
}


int main(int argc, char **argv)
{
	glob_t gl_st;
	int err;
	int i;

	//glob(PAT, 0, NULL, &gl_st);
	err = glob(PAT, 0, &errfunc_, &gl_st);
	if(err)
	{
		printf("Error code = %d\n", err);
		exit(1);
	}
	for(i = 0; i < gl_st.gl_pathc;i++)
		puts(gl_st.gl_pathv[i]);
	
	globfree(&gl_st);

	exit(0);
}
