#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

struct tree_node {
	int key, val;
	struct tree_node *left, *right;
};

struct bstree {
	struct tree_node *root;
};

typedef struct bstree *BSTree;

BSTree BSTree_init();

void BSTree_inorder(BSTree t);
void BSTree_preorder(BSTree t);
void BSTree_postorder(BSTree t);
void BSTree_levelorder(BSTree t);

int BSTree_find(BSTree t, int key);
int BSTree_insert(BSTree t, int key, int value);
int BSTree_delete(BSTree t, int key);
int BSTree_height(BSTree t);

void BSTree_free(BSTree t);

#endif
