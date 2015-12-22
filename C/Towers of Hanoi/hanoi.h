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

void pop(List* first);

void push(List* first, int value);

void print_states(List* from, List* spare, List* to, int n1, int n2, int n3, int max);

void print_dashes(int value);

int count(List* current, int n);

#endif
