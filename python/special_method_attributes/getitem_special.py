class foo:
	def __init__(self, limit):
		self.limit = limit

	def __getitem__(self, key):
		if ((key > self.limit -1) or (key < -(self.limit-1))):
			raise IndexError
		else:
			return 2*key

#f = foo(10)
#print f[0], f[1]
#print f[-3]
#print f[10]