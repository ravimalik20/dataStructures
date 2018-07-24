#include<stdio.h>
#include<stdlib.h>
#include"binary_search_tree.h"

static void preorder(struct tree_node *n);
static void inorder(struct tree_node *n);
static void postorder(struct tree_node *n);
static void tree_free(struct tree_node *n);
static int tree_height(struct tree_node *node);

BSTree BSTree_init()
{
	struct bstree *tree = malloc(sizeof(struct bstree));
	tree->root = NULL;

	return tree;
}

int BSTree_find(BSTree t, int key)
{
	struct tree_node *n = t->root;

	while (n != NULL && n->key != key) {
		if (key > n->key)
			n = n->right;
		else
			n = n->left;
	}

	if (n == NULL)
		return -1;
	else
		return n->val;
}

int BSTree_insert(BSTree t, int key, int value)
{
	struct tree_node *n = malloc(sizeof(struct tree_node));
	n->key = key, n->val = value, n->left = NULL, n->right = NULL;

	if (t->root == NULL) {
		t->root = n;

		return 0;
	}

	struct tree_node *c = t->root, *c_prev = NULL;

	while (c != NULL) {
		c_prev = c;

		if (key > c->key)
			c = c->right;
		else
			c = c->left;
	}

	if (key > c_prev->key)
		c_prev->right = n;
	else
		c_prev->left = n;
}

int BSTree_delete(BSTree t, int key)
{

}

int BSTree_height(BSTree t)
{
	return tree_height(t->root);
}

void BSTree_free(BSTree t)
{
	tree_free(t->root);
	free(t);
}

/* Root - Left - Right */
void BSTree_preorder(BSTree t)
{
	printf ("Preorder: ");
	
	preorder(t->root);

	printf ("\n");
}

/*  Left - Root - Right */
void BSTree_inorder(BSTree t)
{
	printf ("Inorder: ");

	inorder(t->root);

	printf ("\n");
}

/* Left - Right - Root */
void BSTree_postorder(BSTree t)
{
	printf ("Postorder: ");

	postorder(t->root);

	printf ("\n");
}

/* Print nodes at same level, starting from level 0 */
void BSTree_levelorder(BSTree t)
{

}

static int tree_height(struct tree_node *node)
{
	if (node == NULL)
		return 0;

	int lheight = 0, rheight = 0;

	lheight = 1 + tree_height(node->left);
	rheight = 1 + tree_height(node->right);

	if (lheight > rheight)
		return lheight;
	else
		return rheight;
}

static void preorder(struct tree_node *n)
{
	if (n == NULL)
		return ;

	printf ("%d:%d, ", n->key, n->val);
	preorder(n->left);
	preorder(n->right);
}

static void inorder(struct tree_node *n)
{
	if (n == NULL)
		return ;

	inorder(n->left);
	printf ("%d:%d, ", n->key, n->val);
	inorder(n->right);
}

static void postorder(struct tree_node *n)
{
	if (n == NULL)
		return ;

	postorder(n->left);
	postorder(n->right);
	printf ("%d:%d, ", n->key, n->val);
}

static void tree_free(struct tree_node *n)
{
	if (n == NULL)
		return ;

	tree_free(n->left);
	tree_free(n->right);
	free(n);
}
