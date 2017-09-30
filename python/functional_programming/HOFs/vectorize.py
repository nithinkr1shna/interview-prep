
def vectorize(f):
	def g(x):
		return [f(y) for y in x]
	return g

f = vectorize(lambda x: x*x)
print f([1,2,3])

g = vectorize(len)
print g(["hello", "hai"])
print g([[1,2],[2,3,4]])
