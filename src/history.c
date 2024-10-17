#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int sLength(char *str){
  int len = 0;
  while(str[len] != 0){
    len++;
  }
  return len;
}
