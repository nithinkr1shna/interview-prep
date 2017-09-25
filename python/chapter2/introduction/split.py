#split a list into smaller lst of given numbers


def split(list, n):
	length = len(list)
	return  [list[x: x+n] for x in xrange(0, len(list), n)]

print split([1,2,3,4,5,6,7,8], 3)
print split([1,2,3,4,5,6,7,8], 4)
print split([1,2,3,4,5,6,7,8], 5)
print split([1,2,3,4,5,6,7,8], 2)
