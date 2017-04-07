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
}
