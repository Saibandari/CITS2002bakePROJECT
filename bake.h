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
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/param.h>

//int result;
int target_line_counter_buffer; // needed in to know how many target lines are there


void specifier();
void counter();
void comment_check(FILE*);
void read_bakefile();
void actionline(int papi,int mamiS);
void targetname_f();

char * targetname;
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
  int num_dependencies;
  int num_actions;

}TARGETLINE;

TARGETLINE * line;

typedef struct
{
  int num;

} TARGET;

TARGET * trg;
