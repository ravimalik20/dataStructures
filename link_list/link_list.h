#ifndef LINK_LIST_H
#define LINK_LIST_H

typedef struct LinkNode {
	int val;
	struct LinkNode *link;
} LinkNode;

typedef struct LinkList {
	LinkNode *head, *tail;
} LinkList;

LinkList *LinkList_new(void);

void LinkList_free(LinkList *list);

void LinkList_insert(LinkList *list, int item, LinkNode *node);

int LinkList_delete(LinkList *list, LinkNode *node);

#endif
