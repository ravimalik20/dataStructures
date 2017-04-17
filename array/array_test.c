#include<stdio.h>
#include"../local_utils/utils.h"
#include"array.h"

#define ARR_LEN 10

#define ARR_LINEAR_SEARCH(arr, len, item) printf("%d is at position:%d\n", (item), Array_linear_search((arr), (len), (item)))

#define ARR_BINARY_SEARCH(arr, len, item) printf("%d is at position:%d\n", (item), Array_binary_search((arr), (len), (item)))

void main()
{
	int arr[ARR_LEN] = {1, 2, 3, 4, 5, 6, 7 , 8, 9, 10};

	ARR_LINEAR_SEARCH(arr, ARR_LEN, 8);
	ARR_LINEAR_SEARCH(arr, ARR_LEN, 18);

	Array_print(arr, ARR_LEN);

	Array_insert(arr, ARR_LEN, 2, 2);
	Array_print(arr, ARR_LEN);

	Array_delete(arr, ARR_LEN, 4);
	Array_print(arr, ARR_LEN);

	int arr1[4] = {0, 1, 2, 3};
	printf("Is array sorted:%d\n", Array_sorted(arr1, 4, ARRAY_ASC));

	int arr2[4] = {0, 0, 1, 1};
	printf("Is array sorted:%d\n", Array_sorted(arr2, 4, ARRAY_ASC));

	int arr3[4] = {0, 1, 3, 2};
	printf("Is array sorted:%d\n", Array_sorted(arr3, 4, ARRAY_ASC));

	int arr4[1] = {0};
	printf("Is array sorted:%d\n", Array_sorted(arr4, 1, ARRAY_DESC));

	int arr5[10] = {1, 2, 3, 4, 5, 6, 7 , 8, 9, 10};

	ARR_BINARY_SEARCH(arr5, 10, 2);
	ARR_BINARY_SEARCH(arr5, 10, 9);
	ARR_BINARY_SEARCH(arr5, 10, 5);
	ARR_BINARY_SEARCH(arr5, 10, -2);
	ARR_BINARY_SEARCH(arr5, 10, 20);

	int arr6[1] = {1};
	ARR_BINARY_SEARCH(arr6, 1, 2);
	ARR_BINARY_SEARCH(arr6, 1, 1);
	ARR_BINARY_SEARCH(arr6, 1, -2);

	int arr7[10] = {88, 12, 43, 17, 68, 37, 97, 50, 31, 73};
	Array_print(arr7, 10);
	Array_bubble_sort(arr7, 10);
	Array_print(arr7, 10);
	printf("Is array sorted:%d\n", Array_sorted(arr7, 10, ARRAY_ASC));

	int arr8[20] = {876, 603, 307, 197, 517, 701, 854, 636, 469, 298, 436, 158,
		434, 807, 888, 709, 262, 39, 450, 836};
	Array_print(arr8, 20);
	Array_quick_sort(arr8, 20);
	Array_print(arr8, 20);
	printf("Is array sorted:%d\n", Array_sorted(arr8, 20, ARRAY_ASC));

	int arr9[15] = {1781, 171, 127, 45, 780, 1120, 238, 535, 1482, 30, 1786,
		555, 231, 1672, 485};
	Array_print(arr9, 15);
	Array_selection_sort(arr9, 15);
	Array_print(arr9, 15);
	printf("Is array sorted:%d\n", Array_sorted(arr9, 15, ARRAY_ASC));
}
