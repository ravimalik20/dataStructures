#include<stdio.h>
#include"binary_search_tree.h"

#define LEN(arr) ( sizeof((arr)) / sizeof((arr)[0]) )

void main()
{
	BSTree t = BSTree_init();
	int node_values[] = {65, 12, 82, 1, 42, 72, 92, 11, 30};
	int i = 0;

	for (i = 0 ; i < LEN(node_values) ; i++)
		BSTree_insert(t, node_values[i], node_values[i] * 100);

	BSTree_preorder(t);
	BSTree_inorder(t);
	BSTree_postorder(t);
	BSTree_levelorder(t);

	printf ("Find(%d) => %d\n", 42, BSTree_find(t, 42));
	printf ("Find(%d) => %d\n", 40, BSTree_find(t, 40));

	printf ("Height: %d\n", BSTree_height(t));

	BSTree_free(t);
}

