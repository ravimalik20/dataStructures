#ifndef STACK_H
#define STACK_H

#include"../link_list/link_list.h"

typedef LinkList *Stack;

Stack Stack_new(void);

int Stack_push(Stack stack, int item);

int Stack_pop(Stack stack);

void Stack_free(Stack stack);

void Stack_print(Stack stack);

#endif
