""" Write a program to count frequency of characters in a given file.
"""

def freq(filename):
	return count_freq(filter_alpha(read_char(filename)))
	

def read_char(filename):
	char_list =[]
	for line in open(filename).read().split():
		char_list.append([x for x in line])

	return char_list		


def filter_alpha(char_list):
	flattened = [x for x in char_list for x in x]
	letters = map(chr, xrange(97,123))
	return [x for x in flattened if x in letters]

def count_freq(char_list):
	freq_dict = {}
	for char in char_list:
		freq_dict[char] = freq_dict.get(char, 0)+ 1

	return freq_dict




for key, value in freq("file.txt").items():
	print key,":", value