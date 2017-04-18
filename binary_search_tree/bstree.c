#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include<stdbool.h>
#include"bstree.h"

static void preorder(BSNode *node);
static void inorder(BSNode *node);
static void postorder(BSNode *node);

static BSNode *inorder_successor(BSTree *tree, BSNode *node);

BSTree *BSTree_new(void)
{
	BSTree *tree = malloc(sizeof(BSTree));
	tree->root = NULL;

	return tree;
}

int BSTree_insert(BSTree *tree, int val)
{
	assert(tree);

	BSNode *node_new = malloc(sizeof(BSNode));
	if (!node_new)
		return BSTREE_MEM_ALLOC_FAILED;

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

	return BSTREE_SUCCESS;
}

int BSTree_delete(BSTree *tree, BSNode *node)
{
	BSNode *n = tree->root, *node_parent=NULL;
	bool left = false, mem_free = true;

	while (n != NULL && n != node) {
		node_parent = n;

		if (node->val > n->val) {
			n = n->right;
			left = false;
		}
		else {
			n = n->left;
			left = true;
		}
	}

	if (n == NULL)
		return BSTREE_NOT_FOUND;

	/* Deletion logic goes here */
	if (node->left == NULL && node->right == NULL) {
		left ? (node_parent->left = NULL) : (node_parent->right = NULL);
	}
	else if (node->left != NULL && node->right == NULL) {
		left ? (node_parent->left = node->left) : (node_parent->right = node->left);
	}
	else if (node->left == NULL && node->right != NULL) {
		left ? (node_parent->left = node->right) : (node_parent->right = node->right);
	}
	else {
		BSNode *node_successor = inorder_successor(tree, node);
		int node_successor_val = node->val;

		BSTree_delete(tree, node_successor);

		node->val = node_successor_val;

		mem_free = false;
	}

	if (mem_free)
		free(node);

	return BSTREE_SUCCESS;
}

BSNode *BSTree_search(BSTree *tree, int val)
{
	assert(tree);

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
	assert(tree);

	preorder(tree->root);

	putchar('\n');
}

void BSTree_traverse_inorder(BSTree *tree)
{
	assert(tree);

	inorder(tree->root);

	putchar('\n');
}

void BSTree_traverse_postorder(BSTree *tree)
{
	assert(tree);

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

static BSNode *inorder_successor(BSTree *tree, BSNode *node)
{
	BSNode *n = node;

	while (n->left != NULL)
		n = n->left;

	return n;
}
