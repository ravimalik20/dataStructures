def urlify(string):
	res = ""

	for c in string:
		if c == ' ':
			res += '%20'
		else:
			res += c

	return res

data = ["hsakhk hsahas", "adasdsad", "daads asdas asd saad"]

for i in data:
	print (urlify(i))
