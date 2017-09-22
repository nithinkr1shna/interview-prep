
class Shark:
	def swim(self):
		return "shark can swim"

	def swim_b(self):
		return "shark cant swim backwards"

class Clown:
	def swim(self):
		return "clown fish can swim"
	def swim_b(self):
		return "clown fish can swim backwards"

def swim(fish):
	return fish.swim_b()

c = Clown()
s= Shark()
for fish in (c, s):
	#print fish.swim()
	print swim(fish)