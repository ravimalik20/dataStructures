/**
* This interface assumes that array is already created and does not provide
* methods for creation of array, but does provide methods for insertion and
* deletion of array elements.
*/

#ifndef ARRAY_H
#define ARRAY_H

#include<stdbool.h>

#define ARRAY_ASC 100
#define ARRAY_DESC 101

#define ARRAY_NOT_FOUND -1;
#define ARRAY_NOT_SORTED -2;


/**
* Does not modify the length of the array.
*/
void Array_insert(int *arr, int len, int item, int pos);
void Array_delete(int *arr, int len, int pos);

/**
* Array searching functions.
*/
int Array_linear_search(int *arr, int len, int item);
int Array_binary_search(int *arr, int len, int item);

/**
* Check if array is sorted.
* dir = ARRAY_ASC | ARRAY_DESC
*/
bool Array_sorted(int *arr, int len, int dir);

/**
* Array sorting functions.
*/
void Array_bubble_sort(int *arr, int len);
void Array_insertion_sort(int *arr, int len);
void Array_selection_sort(int *arr, int len);
void Array_merge_sort(int *arr, int len);
void Array_quick_sort(int *arr, int len);

#endif
