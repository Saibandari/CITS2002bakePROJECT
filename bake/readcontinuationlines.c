#include "bake.h"

//  Written by Chris.McDonald@uwa.edu.au, September 2018

#if defined(__linux__)
extern  char    *strdup(const char *str);
#endif

#define CH_CONTINUATION         '\\'

void readcontinuationlines(char *bufferfile)
{
        FILE *fp = fopen(bufferfile, "r+");

        if(fp == NULL)
        {
            perror(bufferfile);
        }
        while(!feof(fp))
        {
            char *line = nextline(fp);  // HANDLES CONTINUATION LINES

            if(line)
            {
                fprintf(fp,"%s()\t%s\n", __func__, line);
                free(line);
            }
        }
        fclose(fp);                     // WE OPENED IT, SO WE CLOSE IT
}