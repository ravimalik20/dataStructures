#include<stdio.h>
#include<stdlib.h>
#include"binary_search_tree.h"

static void preorder(struct tree_node *n);
static void inorder(struct tree_node *n);
static void postorder(struct tree_node *n);
static void tree_free(struct tree_node *n);
static int tree_height(struct tree_node *node);
static void levelorder(struct tree_node *n, int level);
static struct tree_node *tree_min(struct tree_node *node);
static struct tree_node *tree_find(struct tree_node *root, int key);
static struct tree_node *tree_in_succ(struct tree_node *node);
static struct tree_node *tree_parent(struct tree_node *root,
	struct tree_node *node);
static void tree_delete(struct tree_node *root, struct tree_node *node,
	struct tree_node *parent);

#define right_orient(node, parent) ( (node)->key > (parent)->key )

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
	/* Locate node and it's parent */
	struct tree_node *node = tree_find(t->root, key);
	if (node == NULL)
		return -1;

	struct tree_node *parent = tree_parent(t->root, node);

	/* Perform delete */
	tree_delete(t->root, node, parent);

	return 0;
}

static void tree_delete(struct tree_node *root, struct tree_node *node,
struct tree_node *parent)
{
	/* Case 1: Leaf node */
	if (node->left == NULL && node->right == NULL) {
		if (right_orient(node, parent))
			parent->right = NULL;
		else
			parent->left = NULL;

		free(node);

		return ;
	}

	/* Case 2: Single child */
	if ( (node->left == NULL && node->right != NULL) ||
	(node->right == NULL && node->left != NULL) ) {
		if (right_orient(node, parent)) {
			if (node->left != NULL)
				parent->right = node->left;
			else if (node->right != NULL)
				parent->right = node->right;
			else
				printf ("Binary tree delete. Error in logic. Re-check. \n");
		}
		else {
			if (node->left != NULL)
				parent->left = node->left;
			else if (node->right != NULL)
				parent->left = node->right;
			else
				printf ("Binary tree delete. Error in logic. Re-check. \n");
		}

		free(node);

		return ;
	}

	/* Case 3: Both children */
	struct tree_node *node_in_succ = tree_in_succ(node);
	struct tree_node *par_in_succ = tree_parent(root, node_in_succ);

	node->key = node_in_succ->key;
	node->val = node_in_succ->val;

	tree_delete(root, node_in_succ, par_in_succ);
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
	int height = tree_height(t->root);
	int i;

	printf ("Levelorder: ");
	for (i=1 ; i <= height ; i++)
		levelorder(t->root, i);

	printf ("\n");
}

int BSTree_min(BSTree t)
{
	struct tree_node *min = tree_min(t->root);

	return min->key;
}

int BSTree_inorder_succ(BSTree t, int key)
{
	struct tree_node *n = tree_find(t->root, key);

	struct tree_node *in_succ = tree_in_succ(n);

	if (in_succ != NULL)
		return in_succ->key;
	else
		return -1;
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

static void levelorder(struct tree_node *n, int level)
{
	if (n == NULL)
		return ;

	if (level == 1) {
		printf ("%d:%d, ", n->key, n->val);

		return ;
	}

	levelorder(n->left, level-1);
	levelorder(n->right, level-1);
}

static void tree_free(struct tree_node *n)
{
	if (n == NULL)
		return ;

	tree_free(n->left);
	tree_free(n->right);
	free(n);
}

static struct tree_node *tree_min(struct tree_node *node)
{
	if (node->left == NULL)
		return node;

	return tree_min(node->left);
}

static struct tree_node *tree_find(struct tree_node *root, int key)
{
	if (root == NULL)
		return NULL;

	while (root != NULL && root->key != key) {
		if (key > root->key)
			root = root->right;
		else
			root = root->left;
	}

	return root;
}

static struct tree_node *tree_in_succ(struct tree_node *node)
{
	if (node == NULL || node->right == NULL)
		return node;

	return tree_min(node->right);
}

static struct tree_node *tree_parent(struct tree_node *root, struct tree_node *node)
{
	struct tree_node *temp = root, *parent = NULL;

	while (temp->key != node->key) {
		parent = temp;

		if (node->key > temp->key)
			temp = temp->right;
		else
			temp = temp->left;
	}

	return parent;
}
