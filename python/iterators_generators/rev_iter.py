
"""reverse iter"""


class rev_iter:
	def __init__(self, n):
		self.n = n
		self.i = len(n) -1

	def __iter__(self):
		return self

	def next(self):
		if self.i >= 0:
			i = self.i
			self.i -=1
			return self.n[i]
		else:
			raise StopIteration()



it = rev_iter([1,2,3,4,5])
for each in it:
	print each