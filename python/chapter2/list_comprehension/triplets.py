"""Write a function triplets that takes a number n as argument and returns a list of triplets 
   such that sum of first two elements of the triplet equals the third element using numbers below n.
   Please note that (a, b, c) and (b, a, c) represent same triplet.
"""

def triplets(limit):
	return [(x,y,z) for x in xrange(limit) for y in xrange(limit) for z in xrange(limit) if x and y and z!= 0 if x+y == z ]
	



print triplets(5)
