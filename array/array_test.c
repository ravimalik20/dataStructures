#include<stdio.h>
#include"array.h"

#define ARR_LEN 10

#define ARR_LINEAR_SEARCH(arr, len, item) printf("%d is at position:%d\n", (item), Array_linear_search((arr), (len), (item)))

void main()
{
	int arr[ARR_LEN] = {1, 2, 3, 4, 5, 6, 7 , 8, 9, 10};

	ARR_LINEAR_SEARCH(arr, ARR_LEN, 8);
	ARR_LINEAR_SEARCH(arr, ARR_LEN, 18);
}
