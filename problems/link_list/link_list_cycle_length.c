#include<stdio.h>
#include"link_list.h"

struct list_elem *list_get_last(List l);
int list_cycle_len(List l);

void main()
{
	List l = list_init();
	int i;

	for (i = 0 ; i < 10 ; i++)
		list_insert(l, i, i*100+10);

	int len_cycle = list_cycle_len(l);
	printf ("Length of cycle: %d\n", len_cycle);

	struct list_elem *last = list_get_last(l);
	/* Made a cycle in the list */
	last->next = l->head;

	len_cycle = list_cycle_len(l);
	printf ("Length of cycle: %d\n", len_cycle);

	/* Make a reduced cyclic link_list */
	last->next = l->head->next->next->next;

	len_cycle = list_cycle_len(l);
	printf ("Length of cycle: %d\n", len_cycle);
}

struct list_elem *list_get_last(List l)
{
	struct list_elem *e;

	for (e = l->head ; e->next != NULL ; e = e->next)
		;

	return e;
}

int list_cycle_len(List l)
{
	struct list_elem *e, *ex2;

	for (e = l->head, ex2 = l->head->next ;
		ex2 != NULL && ex2->next != NULL && ex2->next->next != NULL && e != ex2;
		e = e->next, ex2 = ex2->next->next)
		;

	if (e != ex2)
		return 0;

	int len = 0;
	for (len++, e = e->next ; e != ex2 ; len++, e = e->next)
		;

	return len;
}
