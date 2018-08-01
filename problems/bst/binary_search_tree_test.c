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
	printf ("Min: %d\n", BSTree_min(t));
	printf ("Inorder Succ: %d\n", BSTree_inorder_succ(t, 65));
	printf ("Inorder Succ: %d\n", BSTree_inorder_succ(t, 1000));

	BSTree_free(t);

	BSTree t2 = BSTree_init();
	BSTree_insert(t2, 10, 100);
	BSTree_preorder(t2);
	BSTree_inorder(t2);
	BSTree_postorder(t2);
	BSTree_levelorder(t2);
	printf ("Min: %d\n", BSTree_min(t2));
	printf ("Inorder Succ: %d\n", BSTree_inorder_succ(t, 10));
}

