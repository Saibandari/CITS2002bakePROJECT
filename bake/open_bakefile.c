//
// Created by yasomatinandana
//

#include "bake.h"

// The following function opens the bakefile

FILE * open_bakefile()
{
    const char *filename = "Bakefile";
    const char *filename1 = "bakefile";
    int Bakefile = access(filename, F_OK);
    int bakefile = access(filename1, F_OK);

    if(Bakefile == 0)
    {
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
        fprintf(stderr, "check if a Bakefile or bakefile exists in current directory! \n");
        return NULL;
    }
}
