"""Write a function enumerate that takes a list and returns a list of tuples containing (index,item) for each item in the list.
"""


def my_enumerate(list):
	return [(x, list[x]) for x in xrange(len(list))]


print my_enumerate([1,2,3])

for index, value in enumerate(["a", "b", "c"]):
	print index, value