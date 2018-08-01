#include"binary_search_tree.h"

void mid_add(int *arr, int beg, int end, BSTree t);
BSTree arr_bst_balanced(int *arr, int len);

void main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	BSTree t = arr_bst_balanced(arr, 9);

	BSTree_levelorder(t);
}

BSTree arr_bst_balanced(int *arr, int len)
{
	BSTree t = BSTree_init();

	mid_add(arr, 0, len-1, t);

	return t;
}

void mid_add(int *arr, int beg, int end, BSTree t)
{
	if (beg > end)
		return ;

	int mid = (beg + end) / 2;
	BSTree_insert(t, arr[mid], mid);

	mid_add(arr, beg, mid-1, t);
	mid_add(arr, mid+1, end, t);
}
