#rev orderof lines

def rev_order(filename):
	rev_list =[]
	f = open(filename, "r")
	for line in f.readlines():
		 rev_list.append(line)
		 

	return rev_list[::-1]





for each in rev_order("abc.txt"):
	print each