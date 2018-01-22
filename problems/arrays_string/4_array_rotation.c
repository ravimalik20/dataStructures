/* Left rotate n length array by d places */

#include <stdio.h>

void arr_lrotate(int *arr, int n, int d);

void __array_print(int *arr, int n);

int main(void)
{
	int arr[7] = {1, 2, 3, 4, 5, 6, 7};
	__array_print(arr, 7);
	arr_lrotate(arr, 7, 3);
	__array_print(arr, 7);

	int arr2[7] = {1, 2, 3, 4, 5, 6, 7};
	__array_print(arr2, 7);
	arr_lrotate(arr2, 7, 7);
	__array_print(arr2, 7);

	return 0;
}

void arr_lrotate(int *arr, int n, int d)
{
	int temp[d], i;

	for (i = 0 ; i < d ; i++)
		temp[i] = arr[i];

	for (i = 0 ; i < n-d ; i++)
		arr[i] = arr[i+n-d-1];

	for (i = 0 ; i < d ; i++)
		arr[i+n-d] = temp[i];
}

void __array_print(int *arr, int n)
{
	while (n--)
		printf ("%d ", *arr++);

	printf ("\n");
}
