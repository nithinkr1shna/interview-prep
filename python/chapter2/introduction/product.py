#find produict of a list

def product(list):
	product =1
	for i in list:
		product = product *i

	return product

print product([1, 2, 3, 4])