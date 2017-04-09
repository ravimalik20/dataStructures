#include<stdio.h>
#include"stack.h"

void main()
{
	Stack stk = Stack_new();
	int i = 0;

	for (i = 0 ; i < 20 ; i++)
		Stack_push(stk, i);

	Stack_print(stk);

	for (i = 0 ; i < 5 ; i++)
		printf("Pop: %d\n", Stack_pop(stk));

	Stack_print(stk);
}
