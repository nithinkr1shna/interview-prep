# program to print lines in reverse order

def rev_line(filename):
	f = open(filename, "r")
	line = f.readline()
	while line:
		print reverse(line)
		line = f.readline()

	f.close()


def reverse(string):
	return string[::-1]


rev_line("abc.txt")