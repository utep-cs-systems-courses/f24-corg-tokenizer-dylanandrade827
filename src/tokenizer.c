#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  if (c == '\t' || c == ' ' || c == '\n') return 1;
  return 0;
}

int non_space_char(char c){
  if (c != '\t' && c != ' ' && c != '\n') return 1;
  return 0;
}

char *token_start(char *str){
top:
  if (non_space_char(*str)) return str;
  if (space_char(*str)){
      str++;
      goto top;
  }
  char * ptr = NULL;
  return ptr;
}

char *token_terminator(char *token){
top:
  if (space_char(*token)) return token;
  token++;
  goto top;
}

int count_tokens(char *str){
  int count = 0;

 top:
  if (non_space_char(*str)) goto skip;
  count++;
  str++;
  goto top;

 skip:
  if (*str == '\0') return count;
  str++;
  goto top;
}

char *copy_str(char *inStr, short len){
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

char **tokenize(char *str){
  int len = count_tokens(str);
  char ** tokenizer = malloc((len + 1) * sizeof(char*));
  
  int i = 0;
  char * start = token_start(str);

  while (i < len){
    char * end = token_terminator(start);
    int wordLen = end - start;
    tokenizer[i] = copy_str(start, wordLen);
    start = token_start(end);
    i++;
  }
  tokenizer[len] = NULL;
  return tokenizer;
}

void print_tokens(char **tokens){
  int i = 0;
  
  while(tokens[i] != 0){
    printf("%s", tokens[i]);
    printf("\n");
    i++;
  }
}

void free_tokens(char **tokens){
  int i = 0;

  while(tokens[i] != 0){
    free(tokens[i]);
    i++;
  }
}
