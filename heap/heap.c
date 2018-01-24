#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

#define LEFT(index) ((2 * (index)) + 1)
#define RIGHT(index) ((2 * (index)) + 2)
#define PARENT(index) (((index) - 1) / 2)

static void swap(int *a, int *b);

struct Heap_t {
	int *h;
	int size, len;
};

Heap_t Heap_new(int len)
{
	Heap_t heap = malloc(sizeof (Heap_t));
	heap->h = malloc(sizeof(int)*len);
	heap->size = 0;
	heap->len = 0;

	return heap;
}

int Heap_insert(Heap_t heap,  int val)
{
	int index = heap->len, left = LEFT(index), right = RIGHT(index);

	heap->h[index] = val;
	heap->len ++;
	heap->size ++;

	/* Fix heap property */
	while (index != 0 && heap->h[PARENT(index)] > heap->h[index]) {
		swap(&heap->h[PARENT(index)], &heap->h[index]);
		index = PARENT(index);
	}
}

void Heap_print(Heap_t heap)
{
	int i;

	for (i = 0 ; i < heap->len ; i++) {
		printf ("%d ", heap->h[i]);
	}

	printf ("\n");
}

static void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
