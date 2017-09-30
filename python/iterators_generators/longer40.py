"""Write a program that takes one or more filenames as arguments and prints all the lines which are longer than 40 characters.

"""

import sys


def longerthan_forty(filenames):
	lines = readlines(filenames)
	lines = filter(lines)
	printlines(lines)




def filter(lines):
	return (line for line in lines if len(line) > 40)

def readlines(filenames):
	for f in filenames:
		for line in open(f):
			yield line

def printlines(lines):
	for line in lines:
		print line

try:
	longerthan_forty(sys.argv[1:])
except IndexError:
	print "Error in usage\n"
