#include<stdio.h>
#include"bstree.h"

#define BSTREE_SEARCH(tree, val) printf("%d found at:%p\n", (val), BSTree_search((tree), (val)))

void main()
{
	BSTree *tree = BSTree_new();
	int arr[6] = {67, 17, 57, 87, 9, 45}, i=0;

	for (i = 0; i < 6 ; i++)
		BSTree_insert(tree, arr[i]);

	BSTree_traverse_preorder(tree);
	BSTree_traverse_inorder(tree);
	BSTree_traverse_postorder(tree);

	BSNode *node_searched;
	for (i = 0; i < 6 ; i++) {
		node_searched = BSTree_search(tree, arr[i]);
		if (node_searched)
			printf("%d: ", node_searched->val);
		BSTREE_SEARCH(tree, arr[i]);
	}

	BSTREE_SEARCH(tree, 0);
	BSTREE_SEARCH(tree, -10);
}
