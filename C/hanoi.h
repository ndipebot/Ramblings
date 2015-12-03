#ifndef hanoi_h
#define hanoi_h

typedef struct List {
  int value;
  struct List* next;
} List;

List* populate(int n, int size);

void print(List* node);

void deleteList(List* node);

void hanoi(int size, List* from, List* to, List* spare);

void print_move(List* from, List* to);

int pop(List* first);

void push(List* first, int value);

void print_states(List* from, List* spare, List* to);

void print_dashes(int value);

#endif
