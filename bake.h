#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <unistd.h>

extern FILE * open_bakefile();
extern int specifier();
extern void comment_check(FILE*);
extern void read_bakefile();
