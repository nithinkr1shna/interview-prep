# function that returns list with no duplicates

def uniq(list):
	uniq_list = []
	for each in list:
		if each not in uniq_list:
			uniq_list.append(each)

	return uniq_list


print uniq([1, 2, 3,1 , 5, 6, 2, 3])
