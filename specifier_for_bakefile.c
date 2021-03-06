//specifier_for_bakefile.c

#include "bake.h"
#include "specifier_for_bakefile.h"




void specifier()
{
printf("WE ARE IN SPECIFIER FUNCTION NOW\n");
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
      //below: putting a null byte at the end of the line so then when can fopen later
      counter_var[strlen(counter_var)-1] = '\0';

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

            if (strchr(token_target,':') != NULL)
            {
              //below: elimiating the ':' at the end if there is no space
              token_target[strlen(token_target)-1] = '\0';
            }

            line[i].name = malloc(strlen(token_target) * sizeof(char));
            strcpy(line[i].name,token_target);
            printf("i is: %i\n",i);
            printf("line[%i].name:--%s--\n",i,line[i].name);
            printf("buff_counter_var_target: %s\n",buff_counter_var_target);
            target_or_dependencies++;


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
              //token_target[strlen(token_target)] = '\0';
              line[i].dependencies[j] = token_target;
              //line[i].dependencies[j][strlen(token_target)] = '\0';

              printf("line[%i].dependencies[%i]: --%s--\n",i,j,line[i].dependencies[j]);


              j++;
            }

            //printf("second line[i].dependencies[j]: %s\n",line[i].dependencies[j]);



          }

          token_target = strtok(NULL," \t");
        }
        printf("We are outside of the loop\n");
        printf("i: %i     j: %i\n",i,j);







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
      // If previous line is a targetline / an action line -> true
      {
        printf("%s <--This is an action line\n", counter_var);

        //a = 0, b = 1, stating that this line is an action line and not a target line
        a = 0;
        b = 1;

        //below: reallocating memory since more actions going to be read
        printf("action_counter: %i\ni: %i\n",action_counter,i);
        printf("counter_var: %s\n",counter_var);
        if(i == 0)
        {
          line[i].actions[action_counter] = malloc(strlen(counter_var) * sizeof(char));

        }
        else
        {
          line[i-1].actions[action_counter] = malloc(strlen(counter_var) * sizeof(char));
        }

        printf("counter_var: %s\n",counter_var);

        printf("int action line if statemnt line[0].name is: %s\n",line[0].name);


        strcpy(line[i-1].actions[action_counter],counter_var);

        printf("int action line if statemnt line[0].name is: %s\n",line[0].name);



        printf("line[%i].actions[%i] is:%s\n",i-1,action_counter,line[i-1].actions[action_counter]);

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
  printf("test --- the line[1].name is: %s\n",line[1].name);
  printf("test --- the line[2].name is: %s\n",line[2].name);



  printf("test --- the line[0].dependencies[1] is: %s\n",line[1].dependencies[3]);
  printf("test --- the line[1].dependencies[0] is: %s\n",line[1].dependencies[0]);

  printf("test --- the line[1].dependencies[0][1] is: %c\n",line[1].dependencies[0][1]);

  fclose(buffer_file);
  printf("WE ARE OUTSIDE SPECIFIER FUNCTION NOW\n");

}
