#ifndef DQUEUE_H
#define DQUEUE_H

#include"../link_list/link_list.h"

typedef LinkList *DQueue;

DQueue DQueue_new(void);

int DQueue_insert_beg(DQueue queue, int item);

int DQueue_insert_end(DQueue queue, int item);

int DQueue_fetch_beg(DQueue queue);

int DQueue_fetch_end(DQueue queue);

void DQueue_free(DQueue queue);

void DQueue_print(DQueue queue);

#endif
