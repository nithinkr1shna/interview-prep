""" Write an iterator class reverse_iter, 
that takes a list and iterates it from the reverse direction. ::"""

class reverse_iter:
	def __init__(self, n):
		self.i = 0
		self.n = n

	def __iter__(self):
		return self

	def next(self):
		if self.i < len(self.n):
			i = self.i
			self.i = self.i +1
			return self.n[i]
		else:
			raise StopIteration()


it = reverse_iter([1,2,3,4,5])
for each in it:
	print each
