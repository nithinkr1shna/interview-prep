"""

 Write a function treemap to map a function over nested list.
"""


def treemap(f, li):
	res = []
	for each in li:
		if isinstance(each, list):
			res.append(treemap(f, each))
		else:
			res.append(f(each))


	return res

print treemap(lambda x: x *x, [1,[2,[3,4, [5]]]])