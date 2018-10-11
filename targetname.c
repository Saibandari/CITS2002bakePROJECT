//targetname.c

#include "bake.h"

void targetname_f(char * counter_var, char * default_targetname)
{

//struct stat trgt;
int target_count = 0;
int len = strlen(counter_var);
FILE * file_counter_var = fopen("tokenstorage.txt","a"); // open a file to store the seperated arguments of each counter_var
char * token = strtok(counter_var,":");
char * targetname = (char*)malloc(2);
char * dependencies = (char*)malloc(2);

while(token != NULL)
{
printf("Reading in targetname_f\n");
  if(target_count == 0)//if it's reading the targetname
  {
    targetname = (char*) realloc(targetname,len * sizeof(char*));

    if (strstr(token,default_targetname) == NULL) // this gives me segmentation error
    {
      printf("Not Default target, COPY!!!!!\n");
      strcpy(targetname,token);

      //CHECK WHETHER THE FILE EXIST --> FIND THE MOD DATE --> T
      //IF NOT EXIST --> CREATION DATE IS USED AS T

    }


  }
  else// when it's reading the dependencies
  {
    dependencies = (char*)realloc(dependencies,len * sizeof(char*));
    strcpy(dependencies,token);
    //USE ANOTHER STRTOK TO READ EACH dependencies
        //IS IT .o
        //IS IT files?
        //IS IT URL?
        //find their mod time --> T(Dependencies)
          //IF NONE || T(Targetname) < T(dependencies)
          //rebuild actionline();
  }
  target_count++;

  token = strtok(NULL,":");
}
target_count = 0;
printf("%s\n%s\n",targetname,dependencies);
fclose(file_counter_var);
printf("The while loop finished\n");


  /*if(fopen(default_targetname,"r") == 0)
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
  }*/

fclose(file_counter_var);


  // when the targetname are not the default targetname





}
