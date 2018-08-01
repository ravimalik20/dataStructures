#include<stdio.h>
#include"binary_search_tree.h"

#define LEN(arr) ( sizeof((arr)) / sizeof((arr)[0]) )

void print_traversals(BSTree t)
{
	BSTree_preorder(t);
	BSTree_inorder(t);
	BSTree_postorder(t);
	BSTree_levelorder(t);
}

void main()
{
	BSTree t = BSTree_init();
	int node_values[] = {65, 12, 82, 1, 42, 72, 92, 11, 30};
	int i = 0;

	for (i = 0 ; i < LEN(node_values) ; i++)
		BSTree_insert(t, node_values[i], node_values[i] * 100);

	print_traversals(t);

	printf ("Find(%d) => %d\n", 42, BSTree_find(t, 42));
	printf ("Find(%d) => %d\n", 40, BSTree_find(t, 40));

	printf ("Height: %d\n", BSTree_height(t));
	printf ("Min: %d\n", BSTree_min(t));
	printf ("Inorder Succ: %d\n", BSTree_inorder_succ(t, 65));
	printf ("Inorder Succ: %d\n", BSTree_inorder_succ(t, 1000));

	printf ("Deleting %d. Traversal:\n", 65);
	BSTree_delete(t, 65);
	BSTree_levelorder(t);

	printf ("Deleting %d. Traversal:\n", 30);
	BSTree_delete(t, 30);
	BSTree_levelorder(t);

	printf ("Deleting %d. Traversal:\n", 1);
	BSTree_delete(t, 1);
	BSTree_levelorder(t);	

	BSTree_free(t);
	printf ("\n");


	BSTree t2 = BSTree_init();
	BSTree_insert(t2, 10, 100);
	print_traversals(t2);
	printf ("Min: %d\n", BSTree_min(t2));
	printf ("Inorder Succ: %d\n", BSTree_inorder_succ(t2, 10));
}

