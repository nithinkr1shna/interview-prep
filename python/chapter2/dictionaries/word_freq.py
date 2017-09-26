"""word frequency in a file"""


def word_freq(filename):
	freq= {}
	word_list = read_words(filename)
	for word in word_list:
		freq[word] = freq.get(word, 0) + 1

	return freq 





def read_words(filename):
	return open(filename).read().split()



for key, values in word_freq("file.txt").items():
	print key, ":",values