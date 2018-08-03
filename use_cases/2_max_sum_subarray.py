# To find a sub-array inside the array with the maximum sum

from math import inf

def __max_crossing(arr, beg, mid, end):
	lsum = -1 * inf
	rsum = -1 * inf

	_sum = 0
	for i in range(mid, beg-1, -1):
		_sum += arr[i]
		if _sum > lsum:
			lsum = _sum

	_sum = 0
	for i in range(mid+1, end+1):
		_sum += arr[i]
		if _sum > rsum:
			rsum = _sum

	return lsum + rsum


def __max_subarray(arr, beg, end):
	if beg == end:
		return arr[beg]

	mid = (beg + end) // 2

	lsum = __max_subarray(arr, beg, mid)
	rsum = __max_subarray(arr, mid+1, end)
	csum = __max_crossing(arr, beg, mid, end)

	return max(lsum, rsum, csum)

def max_subarray(arr):
	beg = 0
	end = len(arr) - 1

	return __max_subarray(arr, beg, end)

if __name__ == "__main__":
	arr = [-2, -5, 6, -2, -3, 1, 5, -6]
	print (arr)
	print (max_subarray(arr))

	arr = [-2, -5, 6, -2, -3, 1, 5]
	print (arr)
	print (max_subarray(arr))

	arr = [-2, -5, 6, -2, -3, 1, 5, -6, 11]
	print (arr)
	print (max_subarray(arr))
