# Check if given string has all unique characters

def isUnique(s):
	h = {}

	for c in s:
		if c in h:
			return False

		h[c] = True

	return True

data = ["abcd", "aabcd", "adasdasdasdas"]

for i in data:
	print (isUnique(i))
