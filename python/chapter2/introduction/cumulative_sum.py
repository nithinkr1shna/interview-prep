#find cumulative sum

def cumulative_sum(list):
	cum_list = []
	counter = 0
	for each in list:
		cum_list.append(each+sum(list[0:counter]))
		counter = counter + 1
	return cum_list

def sum(list):
	sum = 0
	for each in list:
		sum = sum +each

	return sum

def sum_str(list):
	#str=""
	str = each.join(list)
	return str

print cumulative_sum([1,2,3,4])