#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/param.h>

FILE * open_bakefile();
void specifier();
void comment_check(FILE*);
void read_bakefile();
void targetname_f(char * buff_counter_var,char * token);

const char * targetname;
char * default_targetname;
char * token;
//FILE * file_counter_var;
