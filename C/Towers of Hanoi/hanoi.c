#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "hanoi.h"


int global_size;
List* tower1;
List* tower2;
List* tower3;


int main(int argc, char* argv[]) {

  //count max size of from tower
  int 
size = atoi(argv[1]);

  global_size = size;
  
  List* from;

  List* to = malloc(sizeof(List*));

  List* spare = malloc(sizeof(List*));


  //Populate from list
  from = populate(1, size);

  //assign global pointers
  tower1 = from;
  tower2 = spare;
  tower3 = to;
  

  print_states(tower1, tower2, tower3, size, 0, 0, size);
  printf("\n");
  printf("\n");
  hanoi(size, from, to, spare);
  
  print(to);

  deleteList(to);

  
  free(from);
  from = NULL;

  free(spare);
  spare = NULL;

  
    return 0;
    
}


List* populate(int n, int size) {
  if(n < size+1) {
    List* first  = malloc(sizeof(struct List));
    first->value = n;
    first->next = populate(n+1, size);
    return first;
      
  } else if(n == size+1) {
    List* first  = malloc(sizeof(struct List));
    first->value = 0;
    first->next = NULL;
    return first;;
  } else
      return NULL;
 }

void print(List* node) {
  if(NULL != node && node->value != 0) {
    printf("%d",node->value);
    printf("\n");
    print(node->next);
  }
}


void deleteList(List* node) {
  if(NULL != node) {
    if(node->value != 0)
      deleteList(node->next);
    free(node);
    node = NULL;
  }
}

void hanoi(int size, List* from, List* to, List* spare) {
  if(size > 0) {
    hanoi(size-1, from,  spare, to);
    print_move(from, to);
    hanoi(size-1, spare, to, from);
  }
}

void print_move(List* from,List* to) {
  int value = from->value;
  pop(from);
  push(to, value);

  //print moves
  int n1 = count(tower1, 0);
  int n2 = count(tower2, 0);
  int n3 = count(tower3, 0);
  int max;
  if (n1 > n2)
    max = (n3 > n1) ? n3 : n1;
  else
    max = (n3 > n2) ? n3 : n2;

  sleep(1);
  print_states(tower1, tower2, tower3, n1, n2, n3, max);
  printf("\n");
  printf("\n");
}

void pop(List* first) {
  List* next = first->next;
  first->next = next->next;
  first->value = next->value;
  free(next);
  next=NULL;
}

void push(List* first, int value) {
  List* new = malloc(sizeof(List));
  new->value = first->value;
  new->next = first->next;
  first->value = value;
  first->next = new;
}



void print_states(List* from, List* spare, List* to, int n1, int n2, int n3, int max) {
  if(max == 0) {
    return;
  } else {

    List* next1 = (n1 != max) ? from : from->next;
    List* next2 = (n2 != max) ? spare : spare->next;
    List* next3 = (n3 != max) ? to : to->next;

    int value1 =  (n1 != max) ? 0 : from->value;
    int value2 =  (n2 != max) ? 0 : spare->value;
    int value3 =  (n3 != max) ? 0 : to->value;
    
    print_dashes(value1);
    print_dashes(value2);
    print_dashes(value3);
    printf("\n");

    n1 =  (n1 != max) ? n1 : (n1 - 1);
    n2 =  (n2 != max) ? n2 : (n2 - 1);
    n3 =  (n3 != max) ? n3 : (n3 - 1);
    max--;
    
    print_states(next1, next2, next3, n1, n2, n3, max);
  } 
}

void print_dashes(int value) {
  for (int i = 0; i < global_size; ++i) {
    if(value > 0)
      printf("__");
    else
      printf("  ");

    value--;
  }
 
  printf("    |    ");
}

int count(List* current, int n) {
  if(current->value == 0)
    return n;
  else
    return count(current->next,n+1);
}
