# reverse a list without list slicing

def rev(list):

	rev_list = []
	for each in xrange(len(list)):
		rev_list.append(list.pop())

	return rev_list

print "rev([1,2,3]):\t",rev([1,2,3])
print "rev(rev([1,2,3])):\t", rev(rev([1,2,3]))
