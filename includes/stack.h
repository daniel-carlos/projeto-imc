#ifndef STACK_H
#define STACK_H

typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Declarações das funções
void stackInit();
int stackIsEmpty();
void stackPush(int data);
int stackPop();
int stackTop();
void stackFree();
void stackPrint();

#endif
