#include "bake.h"

// The following function is to be called at the the beginning of bake to open the bakefile



//The following function disregards any lines in Bakefile or bakefile that start with a #




//The following function is to extract the various text lines within Bakefile or bakefile


int main(int argc, char const *argv[])
{
	FILE * inputFILE = fopen("InputBuffer.txt","a"); // to store the arguments so then can be read using functions
	const char * default_targetname = (char*) malloc(sizeof(argv[argc]));
	default_targetname = argv[argc];

	for (int i = 1; i < argc-1; i++)
  {
    fprintf(inputFILE,"%s\t",argv[i]);
  }

	read_bakefile();
}
