# zip implementation

def my_zip(list1, list2):
	return [(list1[x], list2[x]) for x in xrange( min( len(list1), len(list2) ) ) ]


print my_zip([1,2,3], [4,5,6])
print my_zip([1,2,3,4], [9,8,5])
print my_zip("hello", "hai")