//specifier_for_bakefile.c

#include "bake.h"




void specifier()
{
char counter_var[15000];
char * default_targetname = (char*) malloc (sizeof(char*));
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

      //below: DEFAULT TARGETLINE --> the first target line
      if(strchr(counter_var,':') && targetline_counter == 0)
      {
        printf("counter_var is: %s\n",counter_var);
        a = 1;
        b = 0;

        printf("This is a default targetline\n");
        char * buff_counter_var = (char*)malloc(strlen(counter_var)*sizeof(char*));
        strcpy(buff_counter_var,counter_var);

        //below: getting just the targetname before the ":"
        default_targetname = (char*)realloc(default_targetname,strlen(counter_var)*sizeof(char*));
        default_targetname = strtok(buff_counter_var, " :\t");

        targetname_f(counter_var,default_targetname);
        targetline_counter++;
      }

      //below: this one is for any other target line
      else if(strchr(counter_var,':') && strstr(counter_var,".o"))
      {
        
        printf("Counter var -->%s\n",counter_var);
        a = 1;
        b = 0;


        //PUT THE TARGETNAME FUNCTION HERE !!!!
        targetname_f(counter_var,default_targetname);

        printf("This is a targetline\n");
        //printf("The targetline counter is: %i\n", targetline_counter);
        //when a = 1,b = 0, saying it is a target line and not an action line

      }
      else if(strchr(counter_var,'=') && counter_var[0] != '\t')
      {
        a = 0;
        b = 0;

        //stating that this line is niether an targetline or an action line
        printf("%s <--This is a variable\n", counter_var);
      }
      else if(isspace((int)counter_var[0]) && (a == 1 || b == 1))
      /* since the value of a and b comes from and set from the previous line, it is basically saying
      "If previous line is a targetline / an action line -> true"*/
      {
        a = 0;
        b = 1;

        //a = 0, b = 1, stating that this line is an action line and not a target line
        printf("%s <--This is an action line\n", counter_var);
      }
      else
      {
        a = 0;
        b = 0;
        printf("%s <--This is nothing\n",counter_var);
      }
    }
  }
  fclose(buffer_file);
}
