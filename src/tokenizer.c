#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main(){
  char test[20] = "hello world testing\n";
  char * ptr = test;
  char * copy = copy_str(ptr, 5);
  printf("%s", copy);
  
  char ** tokenizer = tokenize(ptr);
  /*
  int i = 0;
  int count = count_tokens(ptr);
  while (i < count){
    printf("%s", tokenizer[i]);
    i++;
    printf("\n");
  }
  */
  
  return 0;
}

int space_char(char c)
{
  if (c == '\t' || c == ' ' || c == '\n') return 1;
  return 0;
}

int non_space_char(char c)
{
  if (c != '\t' && c != ' ' && c != '\n' && c != '\0') return 1;
  return 0;
}

char *token_start(char *str)
{
top:
  if (non_space_char(*str)) return str;
  
  if (space_char(*str))
    {
      str++;
      goto top;
    }
  char * ptr = NULL;
  return ptr;
}

char *token_terminator(char *token)
{
top:
  if (space_char(*token)) return token;
  
  token++;
  goto top;
}

int count_tokens(char *str)
{
  int count = 0;
  char * ptr = token_start(str);

top:
  if (*ptr == '\0') goto skip;
  
  count++;
  ptr = token_start(token_terminator(str));
  goto top;
    
skip:
  return count;
}

char *copy_str(char *inStr, short len)
{
  char * ptr = malloc((len+1) * sizeof(char));
  int i = 0;
  
 top:
  if (i == len) goto skip;

  *(ptr + i) = *(inStr + i);
  i++;
  goto top;
  
 skip:
  *(ptr + i) = '\0';
  return ptr;
}

char **tokenize(char * str)
{
  int count = count_tokens(str);
  char ** tokenizer = malloc ((count + 1) * sizeof(char*));
  int i = 0;

  char * start = token_start(str);
  char * end;
  int tokenLen = 0;
 top:
  if (i == count) goto skip;

  end = token_terminator(start);
  tokenLen = end - start;
  
  tokenizer[i] = copy_str(start, tokenLen);
  start = token_start(end);
  i++;
  goto top;

 skip:
  tokenizer[count] = NULL;
  return tokenizer;
}
