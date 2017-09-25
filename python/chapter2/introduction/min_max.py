# min and max of a list 
# min and max not using inbuilt functions


def max(a,b):
	if a > b:
		return a
	else:
		return b

def min(a, b):
	if a < b:
		return a
	else:
		return b

def max_list(list):
	max =0
	for each in list:
		if each > max:
			max = each

	return max

def min_list(list):
	min = list[0]
	for each in list:
		if each < min:
			min = each

	return min


#driver

print "min(3, 4):", min(3, 4)
print "max(3, 4):", max(3, 4)
list = [3, 4, 8, 9, 2, 34]
print "list:",list
print "min(list):",min_list(list)
print "max(list):", max_list(list)
