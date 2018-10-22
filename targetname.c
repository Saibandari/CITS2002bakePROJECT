//targetname.c

#include "bake.h"
#include "targetname.h"

void targetname_f()
{

struct stat target;

/*bool present;


struct stat depend;
*/

CURL * curl;

/*int result;
int target_name_does_not_exist;
int len = strlen(buff_counter_var_2);
int start = 0;






char * token = strtok(buff_counter_var_2,":"); // this will get the targetname
int token_len = strlen(token);

printf("target name is: %s\n",token);
printf("Reading in targetname_f\n");
printf("%d--\n",token_len);
*/


//************************************TARGET*********************************************************

    

    printf("targetname: --%s--\n",targetname);
    printf("target_line_counter is: %i\n",trg[0].num);
    printf("line[0].name is: --%s--\n",line[0].name);
    printf("line[1].name is: -%s-\n",line[1].name);
    printf("line[2].name is: -%s-\n",line[2].name);



    if(strcmp(targetname,"default_target")==0)
    {
      targetname = line[0].name;
      printf("default Targetname: %s\n",targetname);
    }

    if (fopen(targetname,"r")!= NULL) // targetname represents a file
    {

      time_t dependencies_time;

      stat(targetname,&target);
      target_time = target.st_mtime;
      printf("%li\n",target_time);

      for(int i = 0; i < trg[0].num; i++)
      {// to iterate through all of the target names
        printf("Hello%i\n",i);
        int d_counter = 0;

        if( strcmp(line[i].name, targetname) == 0)
        {// this if statement is to see through what is inside this target structure

          for(int j = 0; j < line[i].num_dependencies; j++)
          {// iterating through the dependencies of a target we are looking at


            // below: testing whether these dependecies are actually dependencies
            if(strstr(line[i].dependencies[j],"file://") != NULL || strstr(line[i].dependencies[j],"http://") != NULL || strstr(line[i].dependencies[j],"https://") != NULL)
            {
              //below: finding the mtime for URL
              CURLcode res;
              long filetime = -1;

              curl = curl_easy_init();

                 if(!curl)
                 {
                   perror("CURL was unsucessful\n");
                 }
                 else
                 {


                   printf("CURL works-----------\n");
                   curl_easy_setopt(curl, CURLOPT_URL, line[i].dependencies[j]);

                   //No download
                   curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

                   //asking for the filetime
                   curl_easy_setopt(curl, CURLOPT_FILETIME,1L);

                   res  = curl_easy_perform(curl);

                   if(CURLE_OK ==res)
                   {
                     printf("CURLE_OK is equal to res---------\n");
                     res = curl_easy_getinfo(curl,CURLINFO_FILETIME, &filetime);

                     if((CURLE_OK == res) && (filetime >= 0))
                     {
                       time_t file_time = (time_t) filetime;
                       printf("File time is:%li\n", file_time);

                       if(difftime(file_time,buffer_dependencies_time) >= 0)
                       {
                         printf("Comparison between file_time and other time\n");
                         buffer_dependencies_time = file_time;
                       }
                       else
                       {
                         printf("The file is old\n");
                       }
                     }
                     else
                     {
                       perror("Error\n");
                     }
                   }
                 }

                 curl_easy_cleanup(curl);

                d_counter++;
                printf("This is an URL\n");
               printf("This is URL -- Need to use CURL to get the date\n");
            }



            else if (fopen(line[i].dependencies[j],"r") != NULL)
            {

              stat(line[i].dependencies[j],&target);
              dependencies_time = target.st_mtime;
              printf("%li\n",dependencies_time);
              if(difftime(dependencies_time,buffer_dependencies_time) >= 0)
              {
                printf("Comparison between file_time and other time\n");
                buffer_dependencies_time = dependencies_time;
              }
              else
              {
                printf("The file is old\n");
              }



              d_counter++;
              printf("This is file on disk: %s\n",line[i].dependencies[j]);
            }
            else
            {
              for ( int ii = 0; ii < trg[0].num ; ii++)
              {
                if (strcmp(line[i].dependencies[j],line[ii].name) == 0)
                {

                  stat(line[i].dependencies[j],&target);
                  dependencies_time = target.st_mtime;
                  printf("%li\n",dependencies_time);

                  if(difftime(dependencies_time,buffer_dependencies_time) >= 0)
                  {
                    printf("Comparison between file_time and other time\n");
                    buffer_dependencies_time = dependencies_time;
                  }
                  else
                  {
                    printf("The file is old\n");
                  }

                  d_counter++;
                  printf("This one recognised that it's a target name\n");
                  printf("line[i].dependencies[j]: --%s--\n",line[i].dependencies[j]);
                }
                else
                {
                  printf("line[i].dependencies[j]: --%s--\n",line[i].dependencies[j]);
                  perror("Not a dependecy\n");
                }
              }
            }
          }

          if (d_counter == 0)
          {
            printf("No dependencies\n");
            printf("i = %i\n",i);
            actionline(i);
          }
          else
          {
            printf("There is dependencies\n");
            //below: we are checking for updates

            if(difftime(buffer_dependencies_time,target_time) >= 0)
            {
              printf("Need to be updated\n");
              printf("i => %i\n",i);
              actionline(i);

            }
          }



        } // if statement when the file exist
      } // for loop to go through each dependencies

    }

    //IF NOT EXIST --> rebuild
    else
    {
      //actionline();
      printf("ationline here\n");
    }

}





//targetname = (char*) realloc(targetname,len * sizeof(char*));
/*if (strstr(token,default_targetname) == NULL) //if NULL no match -- not default target
{
  printf("Not Default target, COPY!!!!!\n");
  strcpy(targetname,token);

  targetname[strlen(targetname)-1] = '\0';
  printf("target name: %s--\n", targetname);
  time_t target_time;

  //CHECK WHETHER THE FILE EXIST --> FIND THE MOD DATE --> T

}
printf("target time is: %li\n",target_time);
*/


//************************************DEPENDENCIES*********************************************************

/*dependencies = (char*)realloc(dependencies,len * sizeof(char*));
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


      //-----------------------------_________CURL_________--------------------------------------------




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

    }

    printf("There is dependency\n");
    present = 1;

  }
  printf("time prevails: %li\n",buffer_dependencies_time);

  //BELOW: if there is no dependencies then present == 1, hence, rebuilt
  dependencies_token = strtok(NULL, " \t");
}




printf("Absolute prevailing time is: %li\n",buffer_dependencies_time);

if (present != 1 || difftime(buffer_dependencies_time,target_time) >= 0 || target_name_does_not_exist == 1)
{
  printf("Action line function will commence\n");
  result = 1;
  //actionline()
}
else
{
  result = 0;
}
*/
