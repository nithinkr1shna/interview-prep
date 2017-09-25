# cumulative product




def cumulative_product(list):
	new_list = []
	counter = 0
	for each in list:
		new_list.append(each * product(list[0: counter]))
		counter = counter + 1

	return new_list


def product(list):
	pd = 1;
	for each in list:
		pd = pd *each

	return pd


print cumulative_product([1,2,3,4])