#ifndef HEAP_H
#define HEAP_H

#define HEAP_SUCCESS 0
#define HEAP_MEM_ALLOC_FAILED -1

typedef struct Heap_t *Heap_t;

Heap_t Heap_new(int len);

int Heap_insert(Heap_t heap,  int val);

int Heap_delete(Heap_t heap, int val);

void Heap_traverse(Heap_t *heap);

void Heap_print(Heap_t heap);

#endif
