#ifndef LINK_LIST_H
#define LINK_LIST_H

struct list_elem {
	int key, val;
	struct list_elem *next;
};

struct list {
	struct list_elem *head;
	int length;
};

typedef struct list *List;

List list_init();
int list_insert(List l, int key, int val);
int list_fetch(List l, int key);
int list_update(List l, int key, int val);
int list_delete(List l, int key);
int list_free(List l);

#endif
