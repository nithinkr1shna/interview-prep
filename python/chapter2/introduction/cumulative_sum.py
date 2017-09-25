#find cumulative sum

def cumulative_sum(list):
	cum_list = []
	for each in list:
		cum_list.append(each+sum(cum_list))
	return cum_list

def sum(list):
	sum = 0
	for each in list:
		sum = sum +each

	return sum

print cumulative_sum([1,2,3,4])