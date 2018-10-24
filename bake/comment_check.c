//
// Created by yasomatinandana
//

#include "bake.h"

//The following function disregards any lines in Bakefile or bakefile that start with a #

void comment_check(FILE * open_file)
{
    FILE * buffer_file = fopen("Bufferfile.txt", "a");
    long int file_len = 0;
    char *filebuf = NULL;
    char *buffer = read_file_into_buf (&filebuf, &file_len, open_file);
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
}
