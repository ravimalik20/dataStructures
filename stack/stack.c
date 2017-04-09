#include"../link_list/link_list.h"
#include"stack.h"

typedef LinkList Stack_T;

Stack Stack_new(void)
{
	return LinkList_new();
}

int Stack_push(Stack stack, int item)
{
	return LinkList_insert_end(stack, item);
}

int Stack_pop(Stack stack)
{
	LinkNode *list_tail = stack->tail;

	if (!list_tail)
		return 0;

	int val = list_tail->val;

	LinkList_delete(stack, list_tail);

	return val;
}

void Stack_free(Stack stack)
{
	LinkList_free(stack);
}

void Stack_print(Stack stack)
{
	LinkList_print(stack);
}
