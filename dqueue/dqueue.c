#include"../link_list/link_list.h"
#include"dqueue.h"

DQueue DQueue_new(void)
{
	return LinkList_new();
}

int DQueue_insert_beg(DQueue queue, int item)
{
	return LinkList_insert_beg(queue, item);
}

int DQueue_insert_end(DQueue queue, int item)
{
	return LinkList_insert_end(queue, item);
}

int DQueue_fetch_beg(DQueue queue)
{
	LinkNode *node = queue->head;
	if (!node)
		return 0;

	int val = node->val;

	LinkList_delete(queue, node);

	return val;
}

int DQueue_fetch_end(DQueue queue)
{
	LinkNode *node = queue->tail;
	if (!node)
		return 0;

	int val = node->val;

	LinkList_delete(queue, node);

	return val;
}

void DQueue_free(DQueue queue)
{
	LinkList_free(queue);
}

void DQueue_print(DQueue queue)
{
	LinkList_print(queue);
}
