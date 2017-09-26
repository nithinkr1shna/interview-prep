import sys


def grep(filename, string):
	f= open(filename, "r")
	for lines in f.readlines():
		if string in lines:
			print lines


try:
	grep(sys.argv[1], sys.argv[2])
except IndexError:
    print "\nError : python grep.py \"filename\" \"expression\" "
