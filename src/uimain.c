#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char str[1000];
  char exit[4] = "exit";

  int i = 0;
  
 top:
  printf("$ ");
  fgets(str, sizeof(str), stdin);

 check:
  if (str[i] == exit[i])
    {
      if (i == 3 && str[4] == '\n')
	{
	  goto bye;
	}
      i++;
      goto check;
    }
  i = 0;
  printf("%s", str);
  goto top;
  
 bye:
  return 0;
}
