#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

List *init_history(){
  List *list = malloc(sizeof(List));
  list->root = malloc(sizeof(Item));

  return list;
}

void add_history(List *list, char *str){
  int id = 1;
  Item *hold = list->root;

  while (hold->next != 0){
    hold = hold->next;
    id++;
  }

  hold->next = malloc(sizeof(Item));

  int i = 0;
  while(str[i] != 0){
    i++;
  }
  hold->next->str = copy_str(str, i);
  hold->next->id = id;
}

char *get_history(List *list, int id){
  Item *hold = list->root;

  while(hold != 0){
    if(hold->id == id) return hold->str;
    hold = hold->next;
  }
  return "No history available:(";
}

void print_history(List *list){
  Item *hold = list->root->next;
  
  while(hold !=0){
    printf("%d %s\n", hold->id, hold->str);
    hold = hold->next;
  }
}

void free_history(List *list){
  Item *curr = list->root;
  
  while(curr != NULL){
    Item *last = curr;
    
    curr = curr->next;
    free(last->str);
    free(last);
  }
  free(list);
}
