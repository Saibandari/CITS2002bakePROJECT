//targetname.c

#include "bake.h"
#include "targetname.h"

void targetname_f(char * buff_counter_var_2, char * default_targetname)
{
bool present;

struct stat target;
struct stat depend;
//CURL * curl;

int len = strlen(buff_counter_var_2);
int start = 0;


char * targetname = (char*)malloc(2);
char * dependencies = (char*)malloc(2);
char * dependencies_token_2 = (char*)calloc(2 ,sizeof(char*));





char * token = strtok(buff_counter_var_2,":"); // this will get the targetname
int token_len = strlen(token);

printf("target name is: %s\n",token);
printf("Reading in targetname_f\n");
printf("%d--\n",token_len);


//************************************TARGET*********************************************************

targetname = (char*) realloc(targetname,len * sizeof(char*));

if (strstr(token,default_targetname) == NULL) //if NULL no match -- not default target
{
  printf("Not Default target, COPY!!!!!\n");
  strcpy(targetname,token);

  targetname[strlen(targetname)-1] = '\0';
  printf("target name: %s--\n", targetname);

  //CHECK WHETHER THE FILE EXIST --> FIND THE MOD DATE --> T
  if (fopen(targetname,"r")!= NULL)
  {
    stat(targetname,&target);
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
printf("target time is: %i\n",target_time);



//************************************DEPENDENCIES*********************************************************

dependencies = (char*)realloc(dependencies,len * sizeof(char*));
//strcpy(dependencies,token);
//printf("**********%c\n",buff_counter_var_2[token_len]);
printf("We are reading between:%i_____&_____%i\n",token_len,len);
for(int i = token_len; i < len; i++)
{

  //BELOW: To make sure we are only reading the letters, no white spaces from the start
  if (buff_counter_var_2[i] == ' ' || buff_counter_var_2[i] == '\t' || buff_counter_var_2[i] == '\0')
  {
    continue;
  }

  else
  {
    start = i;
    break;
  }

}

printf("i --> : %i\n",start);

//BELOW: below is to copy all of the dependencies into array so then can be seperated using token
for(int j = start ; j < start+1; j++)
{

  dependencies = &buff_counter_var_2[j];

}
printf("Dependencies: %s.\n",dependencies);

//puting null byte at the end so then can be open using fopen for testing existing file
dependencies[strlen(dependencies)-1] = '\0';
time_t buffer_dependencies_time = 0;




//BELOW: seperating each dependencies and analysing them for time
char * dependencies_token = strtok(dependencies," \t");

while(dependencies_token != NULL)
{
  printf("dependencies_token is:%s-\n",dependencies_token);

  //copying the dependecy to put bull byte
  dependencies_token_2 = (char*)realloc(dependencies_token_2,strlen(dependencies_token)*sizeof(char*));
  strcpy(dependencies_token_2,dependencies_token);

  printf("dependencies_token_2 is:%s-\n",dependencies_token_2);

  //below: to check if there is any dependencies
  if (strstr(dependencies_token_2,".o") != NULL || fopen(dependencies_token_2,"r") != NULL || strstr(dependencies_token_2,"file://") != NULL || strstr(dependencies_token_2,"http://") != NULL || strstr(dependencies_token_2,"https://") != NULL) // if it is a target or a file
  {

    //this is if it is for the URL, the obtaining time is different
    if(strstr(dependencies_token_2,"file://") != NULL || strstr(dependencies_token_2,"http://") != NULL || strstr(dependencies_token_2,"https://") != NULL)
    {
      //curl = curl_easy_init()
      printf("This is URL -- Need to use CURL to get the date\n");
    }
    else
    {

      stat(dependencies_token_2,&depend);
      time_t dependencies_time = depend.st_mtime;
      printf("dependencies_time --> %li**\nbuffer_dependencies_time --> %li***\n",dependencies_time,buffer_dependencies_time);

      //below: to make sure any of the dependency
      if (difftime(dependencies_time, buffer_dependencies_time) >= 0)
      {
      //  buffer_dependencies_time = dependencies_time; // effectively saying if the time from this particular dependency is earlier, then copy it to buffer and use that as the time.
        //Always use buffer_dependencies_time for the time as it is updated
        buffer_dependencies_time = dependencies_time;
        printf("The comparison\n");
        //printf("time--> %li\n",buffer_dependencies_time);
      }
      printf("time prevails: %li\n",buffer_dependencies_time);

    }
    printf("time prevails -- inside the else: %li\n",buffer_dependencies_time);

    printf("There is dependency\n");
    present = 1;

  }
  printf("time prevails -- outside the big if: %li\n",buffer_dependencies_time);

  //BELOW: if there is no dependencies then present == 1, hence, rebuilt
  dependencies_token = strtok(NULL, " \t");
}

if (present != 1 || difftime(dependencies_time,target_time) >= 0)
{
  printf("Action line function will commence\n");
  //actionline()
}

  //}
  //target_count++;

  //token = strtok(NULL,":");

//target_count = 0;


//printf("The while loop finished\n");


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



  // when the targetname are not the default targetname


}
