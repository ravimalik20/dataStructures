#include<stdio.h>
#include"bstree.h"

#define BSTREE_SEARCH(tree, val) printf("%d found at:%p\n", (val), BSTree_search((tree), (val)))

#define BSTREE_DELETE(tree, val) printf("Deleting %d: ", (val));\
	BSTree_delete((tree), BSTree_search((tree), (val)));\
	BSTree_traverse_inorder((tree));

#define ARR_LEN 15

void main()
{
	BSTree *tree = BSTree_new();
	int arr[ARR_LEN] = {253, 943, 504, 285, 307, 998, 468, 569, 961, 616, 308, 527,
		788, 979, 498};
	int i = 0;

	for (i = 0; i < ARR_LEN ; i++)
		BSTree_insert(tree, arr[i]);

	BSTree_traverse_preorder(tree);
	BSTree_traverse_inorder(tree);
	BSTree_traverse_postorder(tree);

	BSNode *node_searched;
	for (i = 0; i < ARR_LEN ; i++) {
		node_searched = BSTree_search(tree, arr[i]);
		if (node_searched)
			printf("%d: ", node_searched->val);
		BSTREE_SEARCH(tree, arr[i]);
	}

	BSTREE_SEARCH(tree, 0);
	BSTREE_SEARCH(tree, -10);

	BSTree_traverse_inorder(tree);

	BSTREE_DELETE(tree, 788);
	BSTREE_DELETE(tree, 307);
	BSTREE_DELETE(tree, 285);
	//BSTREE_DELETE(tree, 504);

	BSTree_free(tree);
}
