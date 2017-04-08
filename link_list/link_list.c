#include<stdio.h>
#include<stdlib.h>
#include"link_list.h"

LinkList *LinkList_new(void)
{
	LinkList *list = malloc(sizeof(LinkList));

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
	LinkNode *node_new = malloc(sizeof(LinkNode));
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
	LinkNode *node = malloc(sizeof(LinkNode));
	node->val = item;

	node->link = list->head;
	list->head = node;

	list->count++;

	return 0;
}

int LinkList_insert_end(LinkList *list, int item)
{
	LinkNode *node = malloc(sizeof(LinkNode));
	node->val = item;
	node->link = NULL;

	if (list->tail != NULL)
		list->tail->link = node;

	list->tail = node;

	list->count++;

	return 0;
}

int LinkList_count(LinkList *list)
{
	return list->count;
}

void LinkList_free(LinkList *list)
{
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
	LinkNode *node;

	for (node = list->head; node != NULL; node = node->link)
		if (node->val == item)
			return node;

	return NULL;
}
