#include<assert.h>
#include"array.h"

int Array_linear_search(int *arr, int len, int item)
{
	assert(len > 0);

	int i = 0;

	for (i=0 ; i<len ; i++)
		if (arr[i] == item)
			return i;

	return -1;
}
