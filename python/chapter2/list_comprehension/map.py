#implementation map function

def my_map(fun, list):
	return [fun(x) for x in list]



print map(lambda x: x*x, [2,3,4,5])