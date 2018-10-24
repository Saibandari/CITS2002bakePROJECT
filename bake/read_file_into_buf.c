//
// Created by yasomatinandana
//

#include "bake.h"

char *read_file_into_buf (char **filebuf, long *fplen, FILE *fp)
{
    fseek (fp, 0, SEEK_END);
    if ((*fplen = ftell (fp)) == -1)
    {  /* get file length */
        fprintf (stderr, "error: unable to determine file length.\n");
        return NULL;
    }
    fseek (fp, 0, SEEK_SET);  /* allocate memory for file */
    if (!(*filebuf = calloc (*fplen, sizeof *filebuf)))
    {
        fprintf (stderr, "error: virtual memory exhausted.\n");
        return NULL;
    }

    /* read entire file into filebuf */
    if (!fread (*filebuf, sizeof *filebuf, *fplen, fp))
    {
        fprintf (stderr, "error: file read failed.\n");
        return NULL;
    }

    return *filebuf;
}
