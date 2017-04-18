#ifndef BSTREE_H
#define BSTREE_H

#define BSTREE_MEM_ALLOC_FAILED -1
#define BSTREE_NOT_FOUND -2
#define BSTREE_SUCCESS 0

struct BSNode {
	int val;
	struct BSNode *left, *right;
};

struct BSTree {
	struct BSNode *root;
};

typedef struct BSNode BSNode;
typedef struct BSTree BSTree;

BSTree *BSTree_new(void);

int BSTree_insert(BSTree *tree, int val);

BSNode *BSTree_search(BSTree *tree, int val);

int BSTree_delete(BSTree *tree, BSNode *node);

void BSTree_traverse_preorder(BSTree *tree);

void BSTree_traverse_inorder(BSTree *tree);

void BSTree_traverse_postorder(BSTree *tree);

void BSTree_free(BSTree *tree);

#endif
