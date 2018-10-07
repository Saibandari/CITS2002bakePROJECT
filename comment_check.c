//
// Created by yasom on 7/10/2018.
//

#include "comment_check.h"

//The following function disregards any lines in Bakefile or bakefile that start with a #

void comment_check(FILE * open_file)
{
    char buffer[15000];
    FILE * buffer_file = fopen("Bufferfile.txt", "a");
    while(1)
    {
        if(fgets(buffer, sizeof(buffer), open_file)==NULL) break;
        if (buffer[0] != '#')
        {
            fprintf(buffer_file,"%s",buffer);
        }
        else
        {
            continue;
        }
    }
    fclose(buffer_file);
}

