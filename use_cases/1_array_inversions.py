def count_inversions(arr, beg, end):
	if beg >= end:
		return 0

	mid = (beg + end) // 2

	c1 = count_inversions(arr, beg, mid)
	c2 = count_inversions(arr, mid+1, end)
	count = c1 + c2

	# Merge two sorted arrays and count inversions alongside it

	i = beg
	j = mid + 1
	temp = list()

	while i <= mid and j <= end:
		if arr[i] < arr[j]:
			temp.append(arr[i])
			i += 1
		else:
			temp.append(arr[j])
			j += 1
			count += (mid-i)+1

	while i <= mid:
		temp.append(arr[i])
		i += 1

	while j <= end:
		temp.append(arr[j])
		j += 1

	# Replace arr by temp
	c = beg
	for elem in temp:
		arr[c] = elem
		c += 1

	return count

arr = [2, 4, 1, 3, 5]
count = count_inversions(arr, 0, len(arr)-1)
print (count)
