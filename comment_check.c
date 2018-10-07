#include "bake.h"

void comment_check(FILE * open_file)
{
	char buffer[15000];
	FILE * buffer_file = fopen("Bufferfile.txt", "a");
	while(1)
	{
		//printf("The comment check commennce\n");
		if(fgets(buffer, sizeof(buffer), open_file)==NULL) break;
			if (buffer[0] == '#')
			{
				//printf("it is a comment\n");
				//printf("%s\n",buffer);
				continue;

			}
			else if (buffer[0] == '\n')
			{
				//printf("it is an empty line\n");
				continue;

			}
			else
			{
				//printf("Not a comment or an empty line\n");
				fprintf(buffer_file,"%s",buffer);
			}
	}
	fclose(open_file); // the Bakefile is closed..... but .... the buffer_file (with no comment) is still open
	fclose(buffer_file);
}
