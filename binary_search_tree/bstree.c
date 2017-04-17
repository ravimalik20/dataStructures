#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include"bstree.h"

static void preorder(BSNode *node);
static void inorder(BSNode *node);
static void postorder(BSNode *node);

BSTree *BSTree_new(void)
{
	BSTree *tree = malloc(sizeof(BSTree));
	tree->root = NULL;

	return tree;
}

int BSTree_insert(BSTree *tree, int val)
{
	BSNode *node_new = malloc(sizeof(BSNode));
	if (!node_new)
		return -1;

	node_new->left = NULL;
	node_new->right = NULL;
	node_new->val = val;

	BSNode *node=tree->root, *node_parent=NULL;

	while (node != NULL) {
		node_parent = node;

		if (val > node->val)
			node = node->right;
		else
			node = node->left;
	}

	if (node_parent == NULL)
		tree->root = node_new;
	else if (val > node_parent->val)
		node_parent->right = node_new;
	else
		node_parent->left = node_new;

	return 0;
}

BSNode *BSTree_search(BSTree *tree, int val)
{
	BSNode *node = tree->root;

	while (node != NULL && node->val != val) {
		if (val > node->val)
			node = node->right;
		else
			node = node->left;
	}

	return node;
}

void BSTree_traverse_preorder(BSTree *tree)
{
	preorder(tree->root);

	putchar('\n');
}

void BSTree_traverse_inorder(BSTree *tree)
{
	inorder(tree->root);

	putchar('\n');
}

void BSTree_traverse_postorder(BSTree *tree)
{
	postorder(tree->root);

	putchar('\n');
}

void BSTree_free(BSTree *tree)
{
	assert(tree);

	free(tree);
}

static void preorder(BSNode *node)
{
	if (node == NULL)
		return;

	printf("%d ", node->val);
	preorder(node->left);
	preorder(node->right);
}

static void inorder(BSNode *node)
{
	if (node == NULL)
		return;

	inorder(node->left);
	printf("%d ", node->val);
	inorder(node->right);
}

static void postorder(BSNode *node)
{
	if (node == NULL)
		return;

	postorder(node->left);
	postorder(node->right);
	printf("%d ", node->val);
}
