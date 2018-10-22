#include "bake.h"

void actionline(int i)
{

  printf("Start of the program\n");
  char * environment;
  char * buff_envi = getenv("SHELL");

  int status;

  if (buff_envi == NULL)
  {
    environment = "/bin/bash";
  }
  else
  {
    environment = buff_envi;
  }

  for(int ii = 0; ii < line[i].num_actions;ii++)
  {
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
          exit(EXIT_FAILURE);
          break;

        case 0:
          // we are in the child's process
          printf("We are about to exec it\n");
          execl(environment,"bash","-c",token,NULL);


        default:
        {
          wait(&status);
          exit(WEXITSTATUS(status));
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
          exit(EXIT_FAILURE);
          break;

        case 0:
          // we are in the child's process
          execl(environment,"bash","-c",token,NULL);


        default:
        {
          wait(NULL);
          exit(EXIT_SUCCESS);
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
          exit(EXIT_FAILURE);
          break;

        case 0:
          // we are in the child's process
          execl(environment,"bash","-c",token,NULL);


        default:
        {
          wait(NULL);
          exit(EXIT_SUCCESS);
        }
      }
    }
    else if (strchr(line[i].actions[ii],'@') == NULL && strchr(line[i].actions[ii],'-') == NULL)
    //none exist
    {
      printf("action line is: %s\n",line[i].actions[ii]);
      switch(fork())
      {

        case -1:

          printf("fork() failed\n");
          exit(EXIT_FAILURE);
          break;

        case 0:
          // we are in the child's process
          execl(environment,"bash","-c",token,NULL);


        default:
        {
          wait(&status);
          exit(WEXITSTATUS(status));
        }
      }
    }

  }



}

  /*char * environment;
  char * buff_envi = getenv("SHELL");

  //below: if the targetline requires rebuilding then result == 1
  if (result == 1)
  {
    printf("Will do the operation\n");

    //below: if there is no environment variable called SHELL, buff_envi == NULL
    //and it will set the environment value by default as /bin/bash, if does not exist
    if (buff_envi == NULL)
    {
      environment = "/bin/bash";
    }
    else
    {
      environment = buff_envi;
    }
    printf("%s\n",environment);
    //do the operation
    if(fork() == 0)
    {
      // we are in the child's process
      execl(environment,"bash","-c",counter_var,NULL);

    }
    else
    {
      wait(NULL);
    }
  }
  else
  {
    //do not
    printf("Will NOT do the operation\n");

  }*/
