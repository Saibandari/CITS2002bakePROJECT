//
// Created by yasomatinandana
//

#include "bake.h"


int main (int argc, char **argv) {

    char *srchstr = **;
    char *repstr = **;
    char *filebuf = NULL;
    long int fplen = 0;
    FILE *fp = NULL;

    /* open file for reading (default stdin) */
    fp = argc > 1 ? fopen (argv[1], "r") : stdin;

    if (!fp) {  /* validate file open */
        fprintf (stderr, "error: file open failed '%s'\n", argv[1]);
        return 1;
    }

    if (!read_file_into_buf (&filebuf, &fplen, fp)) return 1;
    if (fplen < 1 || fplen >= INT_MAX) { /* validate file length */
        fprintf (stderr, "error: length of file invalid for fwrite use.\n");
        return 1;
    }
    if (fp != stdin) fclose (fp);

    /* find/replace text in filebuf */
    if (!find_replace_text (srchstr, repstr, filebuf, fplen)) {
        printf ("no replacements made.\n");
        return 0;
    }

    /* open file for writing (default stdout) */
    fp = argc > 1 ? fopen (argv[1], "w") : stdout;

    if (!fp) {  /* validate file open */
        fprintf (stderr, "error: file open failed '%s'\n", argv[1]);
        return 1;
    }

    /* write modified filebuf back to filename */
    if (fwrite (filebuf, sizeof *filebuf, (size_t)fplen, fp) != (size_t)fplen) {
        fprintf (stderr, "error: file write failed.\n");
        return 1;
    }
    if (fp != stdout)
        if (fclose (fp) == EOF) {
            fprintf (stderr, "error: fclose() returned EOF\n");
            return 1;
        }

    free (filebuf);

    return 0;
}