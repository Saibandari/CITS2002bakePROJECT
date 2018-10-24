#include "bake.h"

//  Written by Chris.McDonald@uwa.edu.au, September 2018

#if defined(__linux__)
extern  char    *strdup(const char *str);
#endif

#define CH_CONTINUATION         '\\'

//  DEVELOPED IN LECTURE 9  (but here using pointers)
void trimline(char *line)
{
    while(*line != '\0') {      //  loop until we reach the end of line
        if( *line == '\n' || *line == '\r' ) {
            *line = '\0';       // overwrite with null-byte
            break;              // leave the loop early
        }
        ++line;                 // iterate through characters on line
    }
}
