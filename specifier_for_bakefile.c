#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>



bool comment(char * ch)
{
  char hashtag = '#';

    if (ch[0] == hashtag)
    {
      return true;
    }


  return false;


}


int main(int argc, char const *argv[])
{

  FILE * open_bakefile = fopen("Bakefile.txt","r+");
  char fchar[4000];
  fgets(fchar,sizeof(fchar),open_bakefile);


      if (comment(fchar))
      {
        printf("It is a comment\n");
      }
      else
      {
        printf("It is not a comment");
      }

  return 0;
}
