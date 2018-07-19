#include<stdlib.h>
#include"link_list.h"

void node_del(List l, struct list_elem *parent, struct list_elem *node);

List list_init()
{
	List l = malloc(sizeof(struct list));

	l->length = 0;
	l->head = NULL;

	return l;
}

int list_insert(List l, int key, int val)
{
	struct list_elem *node = malloc(sizeof(struct list_elem));

	node->key = key;
	node->val = val;
	node->next = l->head;

	l->head = node;

	return 0;
}

int list_fetch(List l, int key)
{
	struct list_elem *e;

	for (e = l->head ; e != NULL ; e = e->next) {
		if (e->key == key)
			return e->val;
	}

	return -1;
}

int list_update(List l, int key, int val)
{
	struct list_elem *e;

	for (e = l->head ; e != NULL ; e = e->next) {
		if (e->key == key) {
			e->val = val;
			return 0;
		}
	}

	return -1;
}

int list_delete(List l, int key)
{
	struct list_elem *e, *e_par, *next;

	for (e = l->head, e_par = NULL ; e != NULL ; e_par = e, e = next) {
		next = e->next;

		if (e->key == key) {
			node_del(l, e_par, e);

			return 0;
		}
	}

	return -1;
}

int list_free(List l)
{
	struct list_elem *e, *next;

	for (e = l->head ; e != NULL ; e = next) {
		next = e->next;
		free(e);
	}

	free(l);

	return 0;
}

void node_del(List l, struct list_elem *parent, struct list_elem *node)
{
	if (parent == NULL)
		l->head = node->next;
	else
		parent->next = node->next;

	free(node);
}
