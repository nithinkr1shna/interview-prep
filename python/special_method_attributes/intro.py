class Foo:
	def __init__(self, n):
		print "Constructor called"
		self.n = n

	def hello(self):
		print "Hello World"

	def change(self, n):
		print "changinf self.n"
		self.n = n

		