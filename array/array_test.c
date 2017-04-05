#include<stdio.h>
#include"../local_utils/utils.h"
#include"array.h"

#define ARR_LEN 10

#define ARR_LINEAR_SEARCH(arr, len, item) printf("%d is at position:%d\n", (item), Array_linear_search((arr), (len), (item)))

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
	printf("%d\n", Array_sorted(arr1, 4, ARRAY_ASC));

	int arr2[4] = {0, 0, 1, 1};
	printf("%d\n", Array_sorted(arr2, 4, ARRAY_ASC));

	int arr3[4] = {0, 1, 3, 2};
	printf("%d\n", Array_sorted(arr3, 4, ARRAY_ASC));

	int arr4[1] = {0};
	printf("%d\n", Array_sorted(arr4, 1, ARRAY_DESC));
}
