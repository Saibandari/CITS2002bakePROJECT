#include "bake.h"

void actionline(int i, int ii)
{

  printf("Start of the program\n");
  char * environment;
  char * buff_envi = getenv("SHELL");

  int status = 0;

  if (buff_envi == NULL)
  {
    environment = "/bin/bash";
  }
  else
  {
    environment = buff_envi;
  }

  printf("line[i].num_actions: %i\n",line[i].num_actions);


    printf("line[i].actions[ii]: %s\n",line[i].actions[ii]);

    if(strchr(line[i].actions[ii],'@') != NULL && strchr(line[i].actions[ii],'-') == NULL)
    //only '@' exist
    {
      printf("Only @ found\n");

      printf("line[1].actions[0][2]: %c\n",line[1].actions[0][2]);


      char * token_buff = strtok(line[i].actions[ii],"@");
      printf("token_buff before the loop: %s\n",token_buff);
      int tk = 0;
      char * token;

      while(token_buff != NULL)
      {

        if(tk == 1)
        {
          token = malloc(strlen(token_buff)*sizeof(char));
          token = token_buff;
          printf("token: %s\n",token);
        }
        tk++;
        token_buff = strtok(NULL,"@");
      }

      printf("Token: --%s--\n",token);

      //do the operation
      switch(fork())
      {

        case -1:

          printf("fork() failed\n");
          //exit(EXIT_FAILURE);
          //break;

        case 0:
          // we are in the child's process
          printf("We are about to exec it\n");
          execl(environment,"bash","-c",token,NULL);


        default:
        {
          wait(&status);

          if( WIFEXITED(status) == 0)
          {
            printf("Exit status: SUCCESS\n");

          }
          else
          {
            printf("Exit status: FAILURE\n");
          }
        }

      }
    }
    else if(strchr(line[i].actions[ii],'-') != NULL && strchr(line[i].actions[ii],'@') == NULL)
    //only '-' exist
    {
      printf("action line is: %s\n",line[i].actions[ii]);

      char * token = strtok(line[i].actions[ii],"-");
      switch(fork())
      {

        case -1:

          printf("fork() failed\n");
          //exit(EXIT_FAILURE);
          //break;

        case 0:
          // we are in the child's process
          printf("line[i].actions[ii] is: %s\n",line[i].actions[ii]);
          execl(environment,"bash","-c",token,NULL);


        default:
        {
          wait(NULL);
          //status = 0;
          printf("Exit status: SUCCESS\n");
        }
      }
    }
    else if(strchr(line[i].actions[ii],'@') != NULL && strchr(line[i].actions[ii],'-') != NULL)
    //both exist
    {
      char * token = strtok(line[i].actions[ii],"-@");
      switch(fork())
      {

        case -1:

          printf("fork() failed\n");
          //exit(EXIT_FAILURE);
          //break;

        case 0:
          // we are in the child's process
          printf("both exist -- line[i].actions[ii] is: %s\n",line[i].actions[ii]);

          execl(environment,"bash","-c",token,NULL);


        default:
        {
          wait(NULL);
          //status = 0;
          printf("Exit status: SUCCESS\n");
        }
      }
    }
    else if (strchr(line[i].actions[ii],'@') == NULL && strchr(line[i].actions[ii],'-') == NULL)
    //none exist
    {
      printf("We are now in the NONE section\n");
      printf("action line is: %s\n",line[i].actions[ii]);

      switch(fork())
      {

        case -1:

          printf("fork() failed\n");
          //exit(EXIT_FAILURE);
          //break;

        case 0:
          // we are in the child's process
          printf("none exist -- line[i].actions[ii] is: %s\n",line[i].actions[ii]);

          execl(environment,"bash","-c",token,NULL);


        default:
        {
          wait(&status);

          if( WIFEXITED(status) == 0)
          {
            printf("Exit status: SUCCESS\n");

          }
          else
          {
            printf("Exit status: FAILURE\n");
          }
        }
      }
    }
}
