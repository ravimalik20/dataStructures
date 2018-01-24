#include <stdio.h>
#include "heap.h"

int main(void)
{
	Heap_t heap = Heap_new(10);

	int i = 4;
	while (i > 0) {
		Heap_insert(heap, i--);
	}

	Heap_print(heap);

	return 0;
}
