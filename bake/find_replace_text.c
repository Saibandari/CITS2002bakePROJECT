//
// Created by yasomatinandana
//

#include "bake.h"

unsigned find_replace_text (char *find, char *rep, char *buf, long sz)
{
    long i;
    unsigned rpc = 0;
    size_t j, flen, rlen;

    flen = strlen (find);
    rlen = strlen (rep);

    for (i = 0; i < sz; i++)
    {
        /* if char doesn't match first in find, continue */
        if (buf[i] != *find) continue;

        /* if find found, replace with rep */
        if (strncmp (&buf[i], find, flen) == 0)
        {
            for (j = 0; buf[i + j] && j < rlen; j++)
                buf[i + j] = rep[j];
            if (buf[i + j])
                rpc++;
        }
    }

    return rpc;
}
