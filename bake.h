#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <curl/curl.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/param.h>

int result;

void specifier();
void comment_check(FILE*);
void read_bakefile();
void actionline(char * counter_var, int result);
void targetname_f(char * buff_counter_var_2,char * default_targetname);

const char * targetname;

char * token;

time_t buffer_dependencies_time;
time_t file_time;

FILE * open_bakefile();


typedef struct
{
  char * name;
  char * defaultname;
  char ** dependencies;
  char ** actions;

}TARGETLINE;

TARGETLINE * line;
