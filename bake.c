//bake.c
// compile such: cc -std=c99 -Wall -Werror -pedantic -lcurl -o bake bake.c specifier_for_bakefile.c comment_check.c read_bakefile.c open_bakefile.c targetname.c counter.c
#include "bake.h"


int main(int argc, char const *argv[])
{
	//FILE * inputFILE = fopen("InputBuffer.txt","a"); // to store the arguments so then can be read using functions
	char ** options = malloc(sizeof(char*));
	int cmp = 1;
	char df[23]="default_target";


	printf("Before the targetname allocation\n");

	//printf("line[0].name: %s\n",line[0].name);

			if (argc == 1)
			{//when it's: bake (only)
			targetname = malloc(strlen(df) * sizeof(char));
			targetname = df;
			}
			else if(argc == 2)
			{// when it has 2 arguments only
				if(strstr(argv[argc-1],"-"))
				{ // when it's : bake -options
				targetname = malloc(strlen(df) * sizeof(char));
				targetname = df;
				}
				else
				{ // when it's : bake targetname
				targetname = malloc(strlen(argv[argc-1]) * sizeof(char));
				targetname = (char*)argv[argc-1];
				}
			}
			else
			{// when there are more than 1 / 2 arguments

					for (int i = 1; i < argc; i++)
					{
						if(strstr(argv[i],"-") != NULL)
						{

							//below: storing the options into an array
							options = realloc(options,i * sizeof(char*));
							options[i-1] = malloc(strlen(argv[i]) * sizeof(char));
							options[i-1] = (char*) argv[i];

							cmp++;
						}
						printf("cmp is: %i\n",cmp);
					}

					if ( (argc) == cmp )
					{ // below: when it's : bake -l -a -c ----- the last argv is an option
					targetname = malloc(strlen(df) * sizeof(char));
					targetname = df;
					}
					else
					{ // below: when it's : bake -l -a -c targetname ---- the last argv isn't an options
					targetname = malloc(strlen(argv[argc-1]) * sizeof(char));
					targetname = (char*)argv[argc-1];
					}

			}
	printf("targetname is: %s\n",targetname);

	//printf("options[1]: %s\n",options[1]);


	read_bakefile();
}
