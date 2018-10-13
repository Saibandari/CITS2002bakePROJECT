//targetname.c

#include "bake.h"

void targetname_f(char * counter_var, char * default_targetname)
{

struct stat target;
struct stat depend;
//CURL * curl;

int target_count = 0;
int len = strlen(counter_var);
FILE * file_counter_var = fopen("tokenstorage.txt","a"); // open a file to store the seperated arguments of each counter_var

char * targetname = (char*)malloc(2);
char * dependencies = (char*)malloc(2);
char * dependencies_token_2 = (char*)malloc(2);
//int * dependencies_time = (int*)malloc();

time_t buffer_dependencies_time = 0;



char * token = strtok(counter_var,":");

while(token != NULL)
{
printf("Reading in targetname_f\n");
printf("%i\n",target_count);
  if(target_count == 0)//if it's reading the targetname
  {
    targetname = (char*) realloc(targetname,len * sizeof(char*));

    if (strstr(token,default_targetname) == NULL) //if NULL no match
    {
      printf("Not Default target, COPY!!!!!\n");
      strcpy(targetname,token);

      targetname[strlen(targetname)-1] = '\0';
      printf("target name: %s--\n", targetname);

      //CHECK WHETHER THE FILE EXIST --> FIND THE MOD DATE --> T
      if (fopen(targetname,"r")!= NULL)
      {
        int target_time = target.st_mtime;
        printf("%i\n",target_time);

      }
      //IF NOT EXIST --> rebuild
      else
      {
        //actionline();
        printf("Target line does not represent a file in current directory\n");

      }
    }

  }







  else// when it's reading the dependencies
  {
    dependencies = (char*)realloc(dependencies,len * sizeof(char*));
    strcpy(dependencies,token);

    //USE ANOTHER STRTOK TO READ EACH dependencies

    char * dependencies_token = strtok(dependencies," \t");
    printf("dependency is:%s\ntoken is:%s\n",dependencies_token,token);





    while(dependencies_token != NULL)
    {
      printf("dependencies_token is:%s\n",dependencies_token);

      dependencies_token_2 = (char*)realloc(dependencies_token_2,strlen(dependencies_token)*sizeof(char*));
      strcpy(dependencies_token_2,dependencies_token);

      dependencies_token_2[strlen(dependencies_token_2)] = '\0';
      printf("dependencies_token is:%s\n",dependencies_token);


      if (strstr(dependencies_token_2,".0") != NULL || fopen(dependencies_token_2,"r") != NULL || strstr(dependencies_token_2,"file") != NULL || strstr(dependencies_token_2,"http") != NULL || strstr(dependencies_token_2,"https") != NULL) // if it is a target or a file
      {
        if(strstr(dependencies_token_2,"file:/") != NULL || strstr(dependencies_token_2,"http") != NULL || strstr(dependencies_token_2,"https") != NULL)
        //this is if it is for the URL, the obtaining time is different
        {
          //curl = curl_easy_init()
          printf("****\n");
        }
        else
        {
          time_t dependencies_time = depend.st_mtime;
          printf("**%li**\n***%li***\n",dependencies_time,buffer_dependencies_time);

          //below: to make sure any of the dependency
          if (difftime(dependencies_time, buffer_dependencies_time) >= 0)
          {
          //  buffer_dependencies_time = dependencies_time; // effectively saying if the time from this particular dependency is earlier, then copy it to buffer and use that as the time.
            //Always use buffer_dependencies_time for the time as it is updated
            buffer_dependencies_time = dependencies_time;
            printf("The comparison\n");
            printf("time--> %li\n",buffer_dependencies_time);
          }
          printf("------%li\n",buffer_dependencies_time);

        }

        printf("There is dependency-->%s\n",dependencies_token);

      }


      //IS IT .o || files || URL

      //find their mod time --> T(Dependencies)
        //IF NONE || T(Targetname) < T(dependencies)
        //rebuild actionline();

      dependencies_token = strtok(NULL, " \t");
    }


  }
  target_count++;

  token = strtok(NULL,":");
}
target_count = 0;
printf("&**%s**&\n&***%s***&\n",targetname,dependencies);
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

      //int dependencies_tm = .st_mtime;
      //printf("Mod time is:%i\nAccess time is:%i\n", tm,tma);
    }
  }*/

fclose(file_counter_var);


  // when the targetname are not the default targetname





}
