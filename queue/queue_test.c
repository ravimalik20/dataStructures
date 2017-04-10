#include<stdio.h>
#include"queue.h"

void main()
{
	Queue queue = Queue_new();
	int i = 0;

	for (i = 0 ; i < 20 ; i++)
		Queue_push(queue, i);
	Queue_print(queue);

	for (i = 0 ; i< 5 ; i++)
		printf("Fetch: %d\n", Queue_fetch(queue));
	Queue_print(queue);
}
