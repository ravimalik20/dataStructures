#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"link_list.h"

LinkList *LinkList_new(void)
{
	LinkList *list = malloc(sizeof(LinkList));

	if (!list)
		return NULL;

	list->count = 0;
	list->head = NULL;
	list->tail = NULL;

	return list;
}

/**
* If node is NULL, then place new node at tail
*/
int LinkList_insert(LinkList *list, int item, LinkNode *node)
{
	assert(list != NULL);

	LinkNode *node_new = malloc(sizeof(LinkNode));
	if (!node_new)
		return LL_MEM_ALLOC_FAILED;

	node_new->val = item;
	node_new->link = NULL;

	/* First element to be insered */
	if (node == NULL && list->tail == NULL) {
		list->tail = node_new;
		list->head = node_new;
	}
	else if (node == NULL){
		list->tail->link = node_new;
		list->tail = node_new;
	}
	else {
		node_new->link = node->link;

		node->link = node_new;
	}

	list->count++;

	return 0;
}

int LinkList_insert_beg(LinkList *list, int item)
{
	assert(list != NULL);

	LinkNode *node = malloc(sizeof(LinkNode));
	if (!node)
		return LL_MEM_ALLOC_FAILED;

	node->val = item;

	node->link = list->head;
	list->head = node;

	list->count++;

	return 0;
}

int LinkList_insert_end(LinkList *list, int item)
{
	assert(list != NULL);

	LinkNode *node = malloc(sizeof(LinkNode));
	if (!node)
		return LL_MEM_ALLOC_FAILED;

	node->val = item;
	node->link = NULL;

	if (list->tail != NULL)
		list->tail->link = node;

	list->tail = node;

	list->count++;

	return 0;
}

int LinkList_delete(LinkList *list, LinkNode *node)
{
	LinkNode *node_prev=NULL, *node_temp = list->head;

	while (node_temp != node) {
		node_prev = node_temp;
		node_temp = node_temp->link;
	}

	if (node_temp == NULL)
		return -1;

	if (node_prev == NULL) {
		list->head = node->link;
	}
	else {
		node_prev->link = node->link;
	}

	if (node->link == NULL) {
		list->tail = node_prev;
	}

	free(node);

	list->count--;
}

int LinkList_count(LinkList *list)
{
	assert(list != NULL);

	return list->count;
}

void LinkList_free(LinkList *list)
{
	assert(list != NULL);

	LinkNode *node = list->head, *node_next;

	while (node != NULL) {
		node_next = node->link;
		free(node);

		node = node_next;
	}

	free(list);
}

void LinkList_print(LinkList *list)
{
	assert(list != NULL);

	LinkNode *node = list->head;

	while (node != NULL) {
		printf("%d ", node->val);

		node = node->link;
	}

	putchar('\n');
}

/**
* Returns NULL if not found.
*/
LinkNode *LinkList_search(LinkList *list, int item)
{
	assert(list != NULL);

	LinkNode *node;

	for (node = list->head; node != NULL; node = node->link)
		if (node->val == item)
			return node;

	return NULL;
}
