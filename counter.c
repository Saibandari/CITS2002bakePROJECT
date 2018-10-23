#include "bake.h"
#include "counter.h"

void counter()
{
  printf("WE ARE IN COUNTER FUNCTION NOW\n");

  char counter_var[15000];

  FILE * buffer_file = fopen("Bufferfile.txt","r");

  int target_line_counter = 0;
  int a;
  int b;



  line = malloc(1 * sizeof(TARGETLINE));// giving initial size to the structure array




  while(1)

  {
    printf("Counter nloop works\n");
    if(fgets(counter_var,sizeof(counter_var),buffer_file) == NULL)
    {
      printf("no more to read\n");

      break;
    }
    else
    {
      if(strchr(counter_var,':'))
      {
        action_line_counter = 0;
        printf("Entering if\n");

        line = realloc(line,(target_line_counter+1) * sizeof(TARGETLINE));

        line[target_line_counter].actions = malloc(1 * sizeof(char*));


        printf("This is a target line, when i = 0, then it is the default target\n");

        //below: when a = 1,b = 0, saying it is a target line and not an action line
        a = 1;
        b = 0;
        int j = 0; // the amount of dependencies
        int first_colon = 0;

        char * buff_counter_var_target = malloc(strlen(counter_var)*sizeof(char));
        strcpy(buff_counter_var_target,counter_var);

        int target_or_dependencies = 0;


        char * token_target = strtok(buff_counter_var_target, " \t");

        while(token_target != NULL)
        {

          printf("token_target: %s\n",token_target);

          //below: the first one tokenized will be the targetname
          if(target_or_dependencies == 0)
          {
            printf("This is targetname\n");
            target_or_dependencies++;
          }

          else
          {
            printf("We are looking at the dependencies\n");
            //below: determining the amount of dependencies
            if(strstr(token_target,":") && first_colon == 0)
            {
              first_colon++;
            }

            //below: after the first colon --> dependencies
            else
            {
              j++;
            }
          }




          token_target = strtok(NULL, " \t");


        }

        printf("J is: %i\n",j);
        printf("target_line_counter: %i\n",target_line_counter);

        line[target_line_counter].dependencies = malloc((j+1) * sizeof(char*));

        //below: giving space to the amount of dependencies per target
        line[target_line_counter].num_dependencies = (int)malloc(sizeof(int));
        line[target_line_counter].num_dependencies = j;

        //below: giving space to amount of actions per target
        line[target_line_counter].num_actions = (int)malloc(sizeof(int));


        //below: counts how many targetlines are there
        target_line_counter++;

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
        printf("target counter: %i\n",target_line_counter);

        //a = 0, b = 1, stating that this line is an action line and not a target line
        a = 0;
        b = 1;

        if (target_line_counter == 0)
        {
          line[target_line_counter].actions = realloc(line[target_line_counter].actions,action_line_counter+1 * sizeof(char*));

        }
        else
        {
          line[target_line_counter-1].actions = realloc(line[target_line_counter-1].actions,action_line_counter+1 * sizeof(char*));

        }

        action_line_counter++;
        if(target_line_counter == 0)
        {
          line[target_line_counter].num_actions = action_line_counter;

        }
        else
        {
          line[target_line_counter-1].num_actions = action_line_counter;

        }

      }


      //-----------------------------------------------------------NOTHING-----------------------------------------------------------

      else
      {
        a = 0;
        b = 0;
        printf("%s <--This is nothing\n",counter_var);
      }

      printf("target_line_counter: %i\n",target_line_counter);
    }


  }

  trg = malloc(sizeof(TARGET));
  trg[0].num = (int) malloc(target_line_counter * sizeof(int));
  trg[0].num = target_line_counter;
  printf("outside of the while loop--> target_num: %i\n",trg[0].num);



  fclose(buffer_file);

  printf("WE ARE OUTSIDE COUNTER FUNCTION NOW\n");

}
