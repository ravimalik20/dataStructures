#ifndef QUEUE_H
#define QUEUE_H

#include"../link_list/link_list.h"

typedef LinkList *Queue;

Queue Queue_new(void);

int Queue_push(Queue queue, int item);

int Queue_fetch(Queue queue);

void Queue_free(Queue queue);

void Queue_print(Queue queue);

#endif
