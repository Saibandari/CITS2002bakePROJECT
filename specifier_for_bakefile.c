//specifier_for_bakefile.c

#include "bake.h"




void specifier()
{
char counter_var[15000];
char * buff_counter_var = (char*) malloc (sizeof(char*));
FILE * buffer_file = fopen("Bufferfile.txt","r");


int a;
int b;
int targetline_counter = 0;



  while(1)

  {
    printf("While loop works\n");
    if(fgets(counter_var,sizeof(counter_var),buffer_file) == NULL)
    {
      printf("no more to read\n");

      break;
    }
    else
    {
      //below: this one is to have the full counter_var
      buff_counter_var = (char*)realloc(buff_counter_var,strlen(counter_var)* sizeof(char*));
      strcpy(buff_counter_var,counter_var);

      //below: to seperate strings into each words into tokenstorage.txt
      FILE * file_counter_var = fopen("tokenstorage.txt","a"); // open a file to store the seperated arguments of each counter_var
      char * token = strtok(counter_var," :\t");
      printf("Token works\n");
      while(token != NULL)
      {
        fprintf(file_counter_var,"%s\n",token);
        printf("%s\n",token);
        token = strtok(NULL," :\t");
      }
      fclose(file_counter_var);
      printf("The while loop finished\n");



      //below: DEFAULT TARGETLINE --> the first target line
      if(strchr(buff_counter_var,':') && targetline_counter == 0)
      {
        printf("counter_var is: %s\n",counter_var);
        a = 1;
        b = 0;

        printf("This is a default targetline\n");



        //below: getting just the targetname before the ":"
        char * default_targetname = strtok(counter_var, " :\t");


        targetname_f(buff_counter_var,default_targetname);
        targetline_counter++;
      }

      //below: this one is for any other target line
      else if(strchr(buff_counter_var,':') && strstr(buff_counter_var,".o"))
      {

        a = 1;
        b = 0;


        //PUT THE TARGETNAME FUNCTION HERE !!!!
        targetname_f(buff_counter_var,token);

        printf("This is a targetline\n");
        //printf("The targetline counter is: %i\n", targetline_counter);
        //when a = 1,b = 0, saying it is a target line and not an action line

      }
      else if(strchr(buff_counter_var,'=') && buff_counter_var[0] != '\t')
      {
        a = 0;
        b = 0;

        //stating that this line is niether an targetline or an action line
        printf("%s <--This is a variable\n", counter_var);
      }
      else if(isspace((int)buff_counter_var[0]) && (a == 1 || b == 1))
      /* since the value of a and b comes from and set from the previous line, it is basically saying
      "If previous line is a targetline / an action line -> true"*/
      {
        a = 0;
        b = 1;

        //a = 0, b = 1, stating that this line is an action line and not a target line
        printf("%s <--This is an action line\n", buff_counter_var);
      }
      else
      {
        a = 0;
        b = 0;
        printf("%s <--This is nothing\n",buff_counter_var);
      }
    }
  }
  fclose(buffer_file);
}
