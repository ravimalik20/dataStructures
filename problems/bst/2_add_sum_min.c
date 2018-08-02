/**
* Convert a BST to Binary Tree with sum of all the nodes greater, added to every
* node.
*/

#include "binary_search_tree.h"
#include <stdio.h>

void convert_tree_sum_max(BSTree t);
static void tree_sum_max(struct tree_node *root, int *sum);

void main()
{
	BSTree t = BSTree_init();
	int elems[] = {5, 2, 13}, i;

	for (i = 0 ; i < 3 ; i++) {
		BSTree_insert(t, elems[i], i);
	}
	BSTree_levelorder(t);

	convert_tree_sum_max(t);
	BSTree_levelorder(t);
}

void convert_tree_sum_max(BSTree t)
{
	int sum = 0;

	tree_sum_max(t->root, &sum);
}

static void tree_sum_max(struct tree_node *root, int *sum)
{
	if (root == NULL)
		return;

	tree_sum_max(root->right, sum);

	*sum += root->key;
	root->key = *sum;

	tree_sum_max(root->left, sum);
}
