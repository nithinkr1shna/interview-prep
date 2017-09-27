""" Write a function invertdict to interchange keys and values in a dictionary. 
For simplicity, assume that all values are unique.
"""

def invertdict(dictionary):
	return {value: key for key, value in dictionary.items() }





print invertdict({'x': 1, 'y': 2, 'z': 3})