#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char str[1000];
  char exit[4] = "exit";
  char history[7] = "history";
  char * copy;
  List *list = init_history();
  int i = 0;
  int id = 0;
  
 top:
  printf("$ ");
  fgets(str, sizeof(str), stdin);

  if (str[i] == exit[i]){
    i = 0;
    goto checkExit;
  }

  if (str[i] == history[i]){
    i = 0;
    goto checkHistory;
  }

  if (str[i] == '!'){
    i = 0;
    goto getHistory;
  }
  goto skip;
      
 checkExit:
  if (str[i] != exit[i]) goto skip;
  if (i == 3 && str[4] == '\n') goto bye;
  i++;
  goto checkExit;
  
 checkHistory:
  if (str[i] != history[i]) goto skip;
  if (i == 6 && str[7] == '\n') goto history;
  i++;
  goto checkHistory;

 getHistory:
  id = str[i+1] - '0';
  char * get = get_history(list, id);
  printf("%s", get);
  goto top;
  
 skip:
  copy = copy_str(str, sizeof(str));
  add_history(list, copy);
  char ** tokenizer = tokenize(copy);
  print_tokens(tokenizer);
  
  goto top;

 history:
  print_history(list);
  goto top;
  
 bye:
  free_tokens(tokenizer);
  free_history(list);
  return 0;
}
B
