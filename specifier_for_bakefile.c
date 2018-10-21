//specifier_for_bakefile.c

#include "bake.h"
#include "specifier_for_bakefile.h"




void specifier()
{
char counter_var[15000];

int i = 0; // only to determine whether the target line contains default target name
int a;
int b;

FILE * buffer_file = fopen("Bufferfile.txt","r");


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

      //-----------------------------------------------------------TARGET------------------------------------------------------------

      //below: this one is for any other target line
      if(strchr(counter_var,':'))
      {
        printf("This is a target line, when i = 0, then it is the default target\n");

        // giving more space for the array as now it has more element in the array
        //line = realloc(line,(i+1) * sizeof(TARGETLINE));

        //below: when a = 1,b = 0, saying it is a target line and not an action line
        a = 1;
        b = 0;

        //---------------------------------------------------target name----------------------------------------------
        //below: creating a copy so then can be used just to abstract the default targetname
        char * buff_counter_var_target = malloc(strlen(counter_var)*sizeof(char));
        strcpy(buff_counter_var_target,counter_var);


        //below: getting just the targetname before the ":"
        printf("buff_counter_var_default_target: %s\n",buff_counter_var_target);
        char * token_target = strtok(buff_counter_var_target, " \t");
        int target_or_dependencies = 0;
        int first_colon = 0;
        action_counter = 0;
        int j = 0; // this is for the dependencies -- how many elements in the dependencies array



        while(token_target != NULL)
        {

          //below: the first one tokenized will be the targetname
          if(target_or_dependencies == 0)
          {
            printf("token_target: %s\n", token_target);
            printf("i:%i\n",i);
            printf("before the malloc\n");

            line[i].name = malloc(strlen(token_target) * sizeof(char));
            line[i].name = token_target;
            printf("--%s\n",line[i].name);
            printf("buff_counter_var_target: %s\n",buff_counter_var_target);
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
            //below: after the first colon --> dependencies
            else
            {
              printf("allocation\n");
              printf("i: %i\nj: %i\n",i,j);

              line[i].dependencies[j] = malloc(strlen(token_target) * sizeof(char));
              printf("Test\n");
              line[i].dependencies[j] = token_target;

              printf("line[%i].dependencies[%i]: --%s--\n",i,j,line[i].dependencies[j]);

              j++;
            }

            //printf("second line[i].dependencies[j]: %s\n",line[i].dependencies[j]);



          }

          token_target = strtok(NULL," \t");
          target_or_dependencies++;
        }
        printf("We are outside of the loop\n");
        printf("i: %i     j: %i\n",i,j);







        //below: it will iterate if the line we read was a targetline -- counting how many targets are there
        i++;
        //below: giving memory to the actions array;

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
      // If previous line is a targetline / an action line -> true
      {
        printf("%s <--This is an action line\n", counter_var);

        //a = 0, b = 1, stating that this line is an action line and not a target line
        a = 0;
        b = 1;
        //int ln = 0;



        //still have to be able to seperate between the option and the commands

        /*int do_not_print = 0;
        int exit_always_success = 0;

        char * location_at = strchr(counter_var,'@'); //by default it should print out before execution, but this makes it not printing
        char * location_DASH = strchr(counter_var,'-');//by default it should use exit status for each action, but with this, exist status will always be successfull
        if(location_at != NULL && location_DASH == NULL)
        {
          do_not_print = 1;
          exit_always_success = 0;
          int start = (location_at - counter_var);
          printf("start: %i\n",start);

        }

        else if(location_DASH != NULL && location_at == NULL)
        {
          do_not_print = 0;
          exit_always_success = 1;

        }
        else if(location_DASH == NULL && location_at == NULL)
        {
          do_not_print = 0;
          exit_always_success = 0;
        }
        else
        {
          do_not_print = 0;
          exit_always_success = 0;
        }*/








        //below: reallocating memory since more actions going to be read
        printf("action_counter: %i\ni: %i\n",action_counter,i);
        line[i-1].actions[action_counter] = malloc(strlen(counter_var));
        line[i-1].actions[action_counter] = counter_var;

        printf("line[i-1].actions[action_counter] is:%s\n",line[i-1].actions[action_counter]);

        //below: this is to count how many actions realted to a target
        action_counter++;
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
  printf("test --- the line[0].name is: %s\n",line[0].name);

  printf("test --- the line[0].dependencies[1] is: %s\n",line[1].dependencies[3]);
  printf("test --- the line[1].dependencies[0] is: %s\n",line[1].dependencies[0]);



  fclose(buffer_file);
}
