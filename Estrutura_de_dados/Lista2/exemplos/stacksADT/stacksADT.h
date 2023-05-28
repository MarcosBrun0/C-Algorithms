#ifndef STACKSADT_H_INCLUDED
#define STACKSADT_H_INCLUDED

#include <stdbool.h>

typedef struct node STACK_NODE;
typedef struct stack STACK;

/*	ADT Prototype Declarations */
STACK* createStack  (void);
bool   pushStack    (STACK* stack, void* dataInPtr);
void*  popStack     (STACK* stack);
void*  stackTop     (STACK* stack);
bool   emptyStack   (STACK* stack);
bool   fullStack    (STACK* stack);
int    stackCount   (STACK* stack);
STACK* destroyStack (STACK* stack);


#endif // STACKSADT_H_INCLUDED
