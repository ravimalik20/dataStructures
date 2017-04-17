#include<stdio.h>
#include"bstree.h"

void main()
{
	BSTree *tree = BSTree_new();

	BSTree_insert(tree, 67);
	BSTree_insert(tree, 17);
	BSTree_insert(tree, 57);
	BSTree_insert(tree, 87);
	BSTree_insert(tree, 9);
	BSTree_insert(tree, 45);

	BSTree_traverse_preorder(tree);
	BSTree_traverse_inorder(tree);
	BSTree_traverse_postorder(tree);
}
