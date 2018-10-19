//specifier_for_bakefile.c

#include "bake.h"
#include "specifier_for_bakefile.h"




void specifier()
{
char counter_var[15000];
//char * default_targetname =  malloc (sizeof(char*));
//char * buff_counter_var_2 = malloc (sizeof(char*));
//char * targetname = malloc(2);

int i = 0; // only to determine whether the target line contains default target name
int j = 0; // this is for the dependencies -- how many elements in the dependencies array
int a;
int b;
//int target_counter = 1;

FILE * buffer_file = fopen("Bufferfile.txt","r");

TARGETLINE *line;

line = malloc(1 * sizeof(TARGETLINE));// giving initial size to the structure array

// look for the name in the in all of the array

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

      //-----------------------------------------------------------DEFAULT TARGET------------------------------------------------------
      //below: DEFAULT TARGETLINE --> the first target line
      if(strchr(counter_var,':') && i == 0)
      {
        printf("counter_var is: %s\n",counter_var);

        line = realloc(line,(i+1) * sizeof(TARGETLINE)); // giving more space for the array as now it has more element in the array


        a = 1;
        b = 0;
        printf("This is a default targetline\n");


        //---------------------------------------------------default target name----------------------------------------------
        //below: creating a copy so then can be used just to abstract the default targetname
        char * buff_counter_var_default_target = malloc(strlen(counter_var)*sizeof(char));
        strcpy(buff_counter_var_default_target,counter_var);


        //below: getting just the targetname before the ":"
        char * token_target = strtok(buff_counter_var_default_target, " \t");
        int target_or_dependencies = 0;
        int first_colon = 0;

        while(token_target != NULL)
        {

          line[i].dependencies = malloc(1 * sizeof(char*));

          //below: the first one tokenized will be the targetname
          if(target_or_dependencies == 0)
          {
            line[i].defaultname = (char*) malloc(strlen(token_target) * sizeof(char));
            strcpy(line[i].defaultname,token_target);
            printf("--%s\n",line[i].defaultname);
            printf("buff_counter_var_default_target: %s\n",buff_counter_var_default_target);
          }

          //--------------------------------------------dependencies--------------------------------------------
          //below: second being tokenized is the dependencies
          else
          {
            printf("the dependencies:%s\n",token_target);

            //below: if FIRST COLON, we want to ignore it
            if(strstr(token_target,":") && first_colon == 0)
            {
              first_colon++;
            }
            else
            {
              line[i].dependencies = realloc(line[i].dependencies,(j+1) * sizeof(char*));
              line[i].dependencies[j] = malloc(strlen(token_target) * sizeof(char));
              strcpy(line[i].dependencies[j],token_target);
              printf("line[i].dependencies[j]: %s\n",line[i].dependencies[j]);
            }

            //below: j represent the number of dependencies on a target line
            j++;
          }



          token_target = strtok(NULL," \t");
          target_or_dependencies++;
        }
        free(buff_counter_var_default_target);


        i++;
      }


      //-----------------------------------------------------------TARGET------------------------------------------------------------

      //below: this one is for any other target line
      else if(strchr(counter_var,':'))
      {
        printf("This is a target line\n");

        // giving more space for the array as now it has more element in the array
        line = realloc(line,(i+1) * sizeof(TARGETLINE));

        //below: when a = 1,b = 0, saying it is a target line and not an action line
        a = 1;
        b = 0;



        //---------------------------------------------------target name----------------------------------------------
        //below: creating a copy so then can be used just to abstract the default targetname
        char * buff_counter_var_default_target = malloc(strlen(counter_var)*sizeof(char));
        strcpy(buff_counter_var_default_target,counter_var);


        //below: getting just the targetname before the ":"
        printf("buff_counter_var_default_target: %s\n",buff_counter_var_default_target);
        char * token_target = strtok(buff_counter_var_default_target, " \t");
        int target_or_dependencies = 0;
        int first_colon = 0;

        while(token_target != NULL)
        {

          line[i].dependencies = malloc(1 * sizeof(char*));

          //below: the first one tokenized will be the targetname
          if(target_or_dependencies == 0)
          {
            line[i].name = (char*) malloc(strlen(token_target) * sizeof(char));
            strcpy(line[i].name,token_target);
            printf("--%s\n",line[i].name);
            printf("buff_counter_var_default_target: %s\n",buff_counter_var_default_target);
          }

          //--------------------------------------------dependencies--------------------------------------------
          //below: second being tokenized is the dependencies
          else
          {
            printf("the dependencies:%s\n",token_target);

            if(strstr(token_target,":") && first_colon == 0)
            {
              first_colon++;
            }
            else
            {

              line[i].dependencies = realloc(line[i].dependencies,(j+1) * sizeof(char*));
              line[i].dependencies[j] = malloc(strlen(token_target) * sizeof(char));
              strcpy(line[i].dependencies[j],token_target);
              printf("line[i].dependencies[j]: %s\n",line[i].dependencies[j]);
            }

            j++;
          }

          token_target = strtok(NULL," \t");
          target_or_dependencies++;
        }


        free(buff_counter_var_default_target);

        //below: it will iterate if the line we read was a targetline -- counting how many targets are there
        i++;
      }

      //-----------------------------------------------------------VARIABLE----------------------------------------------------------

      else if(strchr(counter_var,'=') && counter_var[0] != '\t')
      {
        a = 0;
        b = 0;

        //stating that this line is niether an targetline or an action line
        printf("%s <--This is a variable\n", counter_var);
      }

      //-----------------------------------------------------------ACTION LINE------------------------------------------------------

      else if(isspace((int)counter_var[0]) && (a == 1 || b == 1))
      // since the value of a and b comes from and set from the previous line, it is basically saying
      //"If previous line is a targetline / an action line -> true"
      {
        a = 0;
        b = 1;
        actionline(counter_var,result);

        //a = 0, b = 1, stating that this line is an action line and not a target line
        printf("%s <--This is an action line\n", counter_var);
      }

      //-----------------------------------------------------------NOTHING-----------------------------------------------------------

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
