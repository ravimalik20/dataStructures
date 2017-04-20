#ifndef HEAP_H
#define HEAP_H

#define HEAP_SUCCESS 0
#define HEAP_MEM_ALLOC_FAILED -1

struct Heap_node {
	int val;
	struct Heap_node *left, *right, *parent;
};

struct Heap {
	struct Heap_node *root;
};

typedef struct Heap_node Heap_node;
typedef struct Heap Heap;

Heap *Heap_new(void);

int Heap_insert(Heap *heap,  int val);

int Heap_delete(Heap *heap, Heap_node *node);

void Heap_traverse(Heap *heap);

#endif
