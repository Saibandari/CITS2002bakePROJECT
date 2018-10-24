//
// Created by yasomatinandana
//

#ifndef BAKE_BAKE_H
#define BAKE_BAKE_H

#endif //BAKE_BAKE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

extern void comment_check(FILE * open_file);
extern unsigned find_replace_text (char *find, char *rep, char *buf, long sz);
extern char *read_file_into_buf (char **filebuf, long *fplen, FILE *fp);
extern FILE * open_bakefile();
extern char *nextline(FILE *fp);
extern void trimline(char *line);