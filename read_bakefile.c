//read_bakefile.c

#include "bake.h"

TARGETLINE * line;

void read_bakefile()
{
 if(open_bakefile() == NULL)
 {
   printf("can't run without a Bakefile or a bakefile! \n");
 }
 else
 {
   FILE * open_file = open_bakefile();
   comment_check(open_file);
   counter();
   specifier();

 }
}
