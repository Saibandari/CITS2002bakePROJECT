#include "bake.h"

FILE * open_bakefile()
{
	int Bakefile;
	int bakefile;
	const char *filename = "Bakefile";
	const char *filename1 = "bakefile";
	Bakefile = access(filename, F_OK);
	bakefile = access(filename1, F_OK);

	if(Bakefile == 0)
	{
		printf("Bakefile exist\n");
		FILE * open_file;

		open_file = fopen("Bakefile", "r");
		return open_file;
	}
	else if(bakefile == 0)
	{
		FILE * open_file;

		open_file = fopen("bakefile", "r");
		return open_file;
	}
	else
	{
		printf("check if a Bakefile or bakefile exists in current directory! \n");
		return NULL;
	}
}
