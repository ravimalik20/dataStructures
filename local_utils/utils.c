#include<stdio.h>
#include"utils.h"

void Array_print(int *arr, int len)
{
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
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
