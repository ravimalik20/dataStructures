#include<assert.h>
#include<stdio.h>
#include"../local_utils/utils.h"
#include"array.h"

static void quicksort(int *arr, int beg, int end);

/**
* Insert function does not increase the length of the array. It simply swaps
* all the elements starting form the positon, upto the end of array. By this
* logic, the last element of the array is discarded.
*/
void Array_insert(int *arr, int len, int item, int pos)
{
	assert(arr);
    assert(len > 0);
    assert(pos < len);

    int i=0;

    for (i=len-1 ; i > pos ; i--)
        swap(&arr[i], &arr[i-1]);

    arr[pos] = item;
}

/**
* Delete function does not reduce the size of the array. It simply swaps all the
* elements starting from the position, upto the end of array and replaces 0
* with the number to be deleted. 
*/
void Array_delete(int *arr, int len, int pos)
{
	assert(arr);
    assert(len > 0);
    assert(pos < len);

    int i=0;

    for (i=pos; i < len-1 ; i++)
        swap(&arr[i], &arr[i+1]);

    arr[len-1] = 0;
}

int Array_linear_search(int *arr, int len, int item)
{
	assert(arr);
	assert(len > 0);

	int i = 0;

	for (i=0 ; i<len ; i++)
		if (arr[i] == item)
			return i;

	return ARRAY_NOT_FOUND;
}

/**
* Currently only works for arrays sorted in ascending order.
*/
int Array_binary_search(int *arr, int len, int item)
{
	assert(arr);
	assert(len > 0);

	if (!Array_sorted(arr, len, ARRAY_ASC))
		return ARRAY_NOT_SORTED;

	int start=0, end=len, mid=(start+end)/2;

	while (start < end && arr[mid] != item) {
		if (arr[mid] > item)
			end = mid - 1;
		else
			start = mid + 1;

		mid = (start + end) / 2;
	}

	if (arr[mid] == item)
		return mid;
	else
		return ARRAY_NOT_FOUND;
}

bool Array_sorted(int *arr, int len, int dir)
{
	assert(arr);
	assert(len > 0);
	assert(dir == ARRAY_ASC || dir == ARRAY_DESC);

	int i=0;

	for (i=0; i<len-1; i++) {
		if (dir == ARRAY_ASC && arr[i] > arr[i+1])
			return false;

		if (dir == ARRAY_DESC && arr[i] < arr[i+1])
			return false;
	}

	return true;
}

void Array_bubble_sort(int *arr, int len)
{
	assert(arr);
	assert(len > 0);

	int i=0, j=0;

	for (i = 0; i < len ; i++)
		for (j = 0 ; j < len-i-1; j++)
			if (arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
}

void Array_selection_sort(int *arr, int len)
{
	int i = 0, j = 0, i_min;

	for (i = 0; i < len; i++) {
		i_min = i;

		for (j = i ; j < len ; j++) {
			if (arr[j] < arr[i_min])
				i_min = j;
		}

		swap(&arr[i], &arr[i_min]);
	}
}

void Array_quick_sort(int *arr, int len)
{
	assert(arr);
	assert(len > 0);

	quicksort(arr, 0, len-1);
}

static void quicksort(int *arr, int beg, int end)
{
	if (beg > end)
		return ;

	int i=0, pivot=beg;
	bool found = true;

	while (found == true) {
		found = false;

		for (i = end ; i > pivot ; i--) {
			if (arr[i] < arr[pivot]) {
				swap(&arr[i], &arr[pivot]);
				pivot = i;

				found = true;

				break;
			}
		}

		for (i = beg ; i < pivot ; i++) {
			if (arr[i] > arr[pivot]) {
				swap(&arr[i], &arr[pivot]);
				pivot = i;

				found = true;

				break;
			}
		}
	}

	quicksort(arr, beg, pivot-1);
	quicksort(arr, pivot+1, end);
}
