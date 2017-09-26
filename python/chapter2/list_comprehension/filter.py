#filter impementation


def my_filter(fun , list):
	return [x for x in list if fun(x) == True]


print my_filter(lambda x: x%2 == 0, [1,2,3,4,5,6,7,8,9,10])