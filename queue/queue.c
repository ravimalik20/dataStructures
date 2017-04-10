#include<stdio.h>
#include"queue.h"
#include"../link_list/link_list.h"

Queue Queue_new(void)
{
	return LinkList_new();
}

int Queue_push(Queue queue, int item)
{
	return LinkList_insert_end(queue, item);
}

int Queue_fetch(Queue queue)
{
	LinkNode *node_head = queue->head;

	if (node_head == NULL)
		return 0;

	int val = node_head->val;
	LinkList_delete(queue, node_head);

	return val;
}

void Queue_free(Queue queue)
{
	LinkList_free(queue);
}

void Queue_print(Queue queue)
{
	LinkList_print(queue);
}
