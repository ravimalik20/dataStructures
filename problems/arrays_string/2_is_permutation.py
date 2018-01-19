def __count_chars(string):
	hash_count = {}

	for c in string:
		if c in hash_count:
			hash_count[c] += 1
		else:
			hash_count[c] = 0

	return hash_count

def __match_keys(h1, h2):
	for key in h1:
		if key not in h2:
			return False

	return True

def __match_counts(h1, h2):
	for key in h1:
		if h1[key] != h2[key]:
			return False

	return True

def is_perm(s1, s2):
	h1 = __count_chars(s1)
	h2 = __count_chars(s2)

	if len(h1) != len(h2):
		return False

	if not __match_keys(h1, h2):
		return False

	if not __match_counts(h1, h2):
		return False

	return True

data = [("abcd", "dcab"), ("aabcdefg", "gdaefbca"),
	("gasgasjasg", "jsaljsaljksaljkas")]

for i in data:
	print (is_perm(i[0], i[1]))
