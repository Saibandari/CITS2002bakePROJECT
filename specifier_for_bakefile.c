#include "bake.h"


char * specifier()
{
char counter_var[15000];
FILE * buffer_file = fopen("Bufferfile.txt","a");
extern char * a;
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
        a = "This is a targetline";
      }
      else if(strchr(counter_var,'=') == 0 && counter_var[0] != '\t')
      {
        a = "This is a comment";
      }
      else if(counter_var[0] == '\t')
      {
        a = "This is an action line";
      }
    }
  }
  return(&a);
}
