#include<stdio.h>
#include"link_list.h"

int list_cycle(List l);
struct list_elem *list_last_elem(List l);

void main()
{
	List l = list_init();
	int i;

	for (i = 0 ; i < 10 ; i++) {
		list_insert(l, i, i*10);
	}

	printf ("%d\n", list_cycle(l));

	struct list_elem *last = list_last_elem(l);

	/* Cycle created */
	last->next = l->head;

	printf ("%d\n", list_cycle(l));
}

struct list_elem *list_last_elem(List l)
{
	struct list_elem *e;

	for (e = l->head ; e->next != NULL ; e = e->next)
		;

	return e;
}

int list_cycle(List l)
{
	struct list_elem *i, *ix2;

	for (i = l->head, ix2 = l->head->next ;
	ix2 != NULL && ix2->next != NULL && ix2->next->next != NULL && i != ix2 ;
	i = i->next, ix2 = ix2->next->next)
		;

	if (i == ix2)
		return 1;
	else
		return 0;
}
