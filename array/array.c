#include<assert.h>
#include"../local_utils/utils.h"
#include"array.h"

/**
* Insert function does not increase the length of the array. It simply swaps
* all the elements starting form the positon, upto the end of array. By this
* logic, the last element of the array is discarded.
*/
void Array_insert(int *arr, int len, int item, int pos)
{
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
    assert(len > 0);
    assert(pos < len);

    int i=0;

    for (i=pos; i < len-1 ; i++)
        swap(&arr[i], &arr[i+1]);

    arr[len-1] = 0;
}

int Array_linear_search(int *arr, int len, int item)
{
	assert(len > 0);

	int i = 0;

	for (i=0 ; i<len ; i++)
		if (arr[i] == item)
			return i;

	return -1;
}

bool Array_sorted(int *arr, int len, int dir)
{
	assert(len >0);
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
