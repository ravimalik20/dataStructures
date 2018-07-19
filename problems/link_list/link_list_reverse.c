#include<stdio.h>
#include"link_list.h"

void list_print(List l);
void list_reverse(List l);

void main()
{
	List l = list_init();
	int i;

	for (i = 0 ; i < 10 ; i++)
		list_insert(l, i, i*100+10);

	list_print(l);

	list_reverse(l);
	list_print(l);

	list_free(l);
}

void list_print(List l)
{
	struct list_elem *e;

	printf ("List:\n");
	for (e = l->head ; e != NULL ; e = e->next)
		printf ("%d: %d\n", e->key, e->val);
}

void list_reverse(List l)
{
	struct list_elem *e_prev, *e, *e_next;

	for (e = l->head, e_prev = NULL ; e != NULL ; e = e_next) {
		e_next = e->next;
		e->next = e_prev;
		e_prev = e;
	}

	l->head = e_prev;
}
