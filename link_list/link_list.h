#ifndef LINK_LIST_H
#define LINK_LIST_H

#define LL_MEM_ALLOC_FAILED -1

typedef struct LinkNode {
	int val;
	struct LinkNode *link;
} LinkNode;

typedef struct LinkList {
	int count;
	LinkNode *head, *tail;
} LinkList;

LinkList *LinkList_new(void);

void LinkList_free(LinkList *list);

int LinkList_insert(LinkList *list, int item, LinkNode *node);

int LinkList_insert_beg(LinkList *list, int item);

int LinkList_insert_end(LinkList *list, int item);

int LinkList_delete(LinkList *list, LinkNode *node);

void LinkList_print(LinkList *list);

int LinkList_count(LinkList *list);

#endif
