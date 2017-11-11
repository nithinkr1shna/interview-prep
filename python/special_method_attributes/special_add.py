class Foo:
	def __init__(self, n):
		self.n = n

	def __add__(self, right):
		t = Foo(0) # creating an object to save the value of addition in the next step.
		t.n = self.n + right.n
		return t

f1 = Foo(10)
f2 = Foo(30)
f3 = f1+f2
print f3.n
