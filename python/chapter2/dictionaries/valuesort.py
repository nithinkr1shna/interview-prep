"""Write a function valuesort to sort values of a dictionary based on the key."""

def valuesort(dictionary):
	return [dictionary[key] for key in sorted(dictionary.keys())]


print valuesort({'x':1, 'y':2, 'a':3})