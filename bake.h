#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <unistd.h>

FILE * open_bakefile();
int specifier();
void comment_check(FILE*);
void read_bakefile();
void targetname();

const char * default_targetname;
