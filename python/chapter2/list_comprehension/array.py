"""Write a function array to create an 2-dimensional array. The function should take both dimensions as arguments.
   Value of each element can be initialized to None:
"""



def my_array(listlen1, listlen2):
	return [[None for x in xrange(listlen2) ] for x in xrange(listlen1)]

arr =  my_array(2,3)
arr[0][0] = 5
print arr