#include "bake.h"




int specifier()
{
char counter_var[15000];
FILE * buffer_file = fopen("Bufferfile.txt","r");
int a;


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

      printf("Something to read\n");
      printf("%s    <-",counter_var);
      
      if(strchr(counter_var,':'))
      {
        a = 1;
        printf("This is a targetline\n");
      }
      else if(strchr(counter_var,'=') && counter_var[0] != '\t')
      {
        a = 2;
        printf("This is a variable\n");
      }
      else if(isspace((int)counter_var[0]))
      {
        a = 3;
        printf("This is an action line\n");
      }
    }
  }
  return a;
}
