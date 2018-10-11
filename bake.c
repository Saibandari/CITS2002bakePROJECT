//bake.c

#include "bake.h"


int main(int argc, char const *argv[])
{
	FILE * inputFILE = fopen("InputBuffer.txt","a"); // to store the arguments so then can be read using functions

	const char * targetname = (char*) malloc(sizeof(argv[argc]));
	targetname = argv[argc];

	for (int i = 1; i < argc-1; i++)
  {
    fprintf(inputFILE,"%s\t",argv[i]);
  }

	read_bakefile();
}
