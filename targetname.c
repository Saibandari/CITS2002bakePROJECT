//targetname.c

#include "bake.h"

void targetname_f(char * buff_counter_var, char * default_targetname)
{

FILE * file_counter_var = fopen("tokenstorage.txt","r+");

printf("targetname_function works\n");
printf("counter_var is: %s\n",buff_counter_var);

struct stat trgt;

  if(fopen(default_targetname,"r") == 0)
  {
    printf("The file is not found\n");

  }
  else // there is a file in current directory
  {
    if (stat(default_targetname, &trgt) != 0)
    {
      printf("Stat couldn't be preformed\n");
    }
    else // can be read
    {
      printf("Haiii\n");
      //int target_tm = tgrt.st_mtime;
      //int dependencies_tm = .st_mtime;
      //printf("Mod time is:%i\nAccess time is:%i\n", tm,tma);
    }
  }

fclose(file_counter_var);


  // when the targetname are not the default targetname





}
