#include<stdio.h>
#include"dqueue.h"

void main()
{
	int i = 0;
	DQueue queue = DQueue_new();

	for (i = 0; i < 10 ; i++)
		DQueue_insert_beg(queue, i);

	for (i = 0; i < 10 ; i++)
		DQueue_insert_end(queue, i);

	DQueue_print(queue);

	for (i = 0 ; i < 5 ; i++)
		printf("Get Beg:%d\n", DQueue_fetch_beg(queue));

	for (i = 0 ; i < 5 ; i++)
		printf("Get End:%d\n", DQueue_fetch_end(queue));

	DQueue_print(queue);

	DQueue_free(queue);
}
