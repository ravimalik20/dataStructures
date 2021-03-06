#include<stdio.h>
#include"link_list.h"

void main()
{
	LinkList *list = LinkList_new();

	int i=0;

	for (i=0 ; i<20; i++) {
		LinkList_insert(list, i, NULL);
	}

	printf("Count:%d | List: ", LinkList_count(list));
	LinkList_print(list);

	LinkList_insert(list, -10, list->head->link);

	printf("Count:%d | List: ", LinkList_count(list));
	LinkList_print(list);

	LinkList_insert(list, -10, list->head);

	printf("Count:%d | List: ", LinkList_count(list));
	LinkList_print(list);

	LinkList_insert_beg(list, -98);
	LinkList_insert_beg(list, -99);
	LinkList_insert_end(list, 98);
	LinkList_insert_end(list, 99);

	printf("Count:%d | List: ", LinkList_count(list));
	LinkList_print(list);

	LinkList_delete(list, list->head);
	printf("Count:%d | List: ", LinkList_count(list));
	LinkList_print(list);

	LinkList_delete(list, list->head->link->link);
	printf("Count:%d | List: ", LinkList_count(list));
	LinkList_print(list);

	LinkList_delete(list, list->tail);
	printf("Count:%d | List: ", LinkList_count(list));
	LinkList_print(list);

	printf("%d found at position: %p\n", 7, LinkList_search(list, 7));
	printf("%d found at position: %p\n", -199, LinkList_search(list, -199));

	LinkList_free(list);
}
