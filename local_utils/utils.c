#include<stdio.h>
#include<assert.h>
#include"utils.h"

void Array_print(int *arr, int len)
{
	assert(arr);

	int i;

	for (i=0; i<len; i++) {
		printf("%d", arr[i]);

		if (i < len-1) {
			putchar(' ');
		}
	}

	putchar('\n');
}

void swap(int *a, int *b)
{
	assert(a);
	assert(b);

	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
