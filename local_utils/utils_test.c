#include<stdio.h>
#include"utils.h"

#define ARR_LEN 10

void main()
{
	int a=10, b=20, arr[ARR_LEN] = {0};

	printf("%d %d\n", a, b);
	swap(&a, &b);
	printf("%d %d\n", a, b);

	Array_print(arr, ARR_LEN);
}
