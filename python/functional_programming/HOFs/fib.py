"""IMpement fib with memoize"""



def fib(num, cache):
	if num == 0 or num == 1:
		return 1
	else:
		val1 = num-1
		val2 = num-2
		if val2 in cache:
			value2 = cache[val2]
		else:
			value2 = fib(val2, cache)
			cache[val2] = value2
		if val1 in cache:
			value3 = cache[val1]
		else:
			value3 = fib(val1, cache)
			cache[val1] = value3



		return value3 + value2


memoize = {}
print fib(1, memoize)
for i in xrange(10000):
	print fib(i,memoize)
