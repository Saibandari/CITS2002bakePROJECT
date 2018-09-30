#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>




void comment(FILE * open_bakefile)
{

  char counter[15000];

  printf("This is the new line character\n");
  FILE * buffer_file = fopen("Bufferfile.txt", "a");

  while(1)
  {
    if(fgets(counter, sizeof(counter), open_bakefile)==NULL) break;
      if (counter[0] != '#')
      {
        fprintf(buffer_file,"%s",counter);
      }
      else
      {
        continue;
      }
  }

}




int main(int argc, char const *argv[])
{
  FILE * open_bakefile = fopen("Bakefile", "r");

  if(open_bakefile == NULL)
  {
    open_bakefile = fopen("bakefile" , "r");
    comment(open_bakefile);
    if (open_bakefile == NULL)
    {
      printf("No file can be used");
    }
  }
  else
  {
    comment(open_bakefile);
  }



//printf("%i\n", n);
fclose(open_bakefile);
//printf("\n\nnth number of elements:  %i \n\n\n",line - 2);

return 0;
}
