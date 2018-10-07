#include "bake.h"




void specifier()
{
char counter_var[15000];
FILE * buffer_file = fopen("Bufferfile.txt","a");
char * a;
  while(1)

  {
    //printf("While loop works\n");
    if(fgets(counter_var,sizeof(counter_var),buffer_file) == NULL)
    {
      printf("no more to read\n");
      break;
    }
    else
    {
      if(strchr(counter_var,':') == 0)
      {
        printf("This is a targetline\n");
      }
      else if(strchr(counter_var,'=') == 0 && counter_var[0] != '\t')
      {
        printf("This is a comment\n")
      }
      else if(counter_var[0] == '\t')
      {
        printf("This is an action line\n")
      }
    }
  }
  return 0;
}
