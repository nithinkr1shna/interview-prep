"""Write a program to print directory tree. 
The program should take path of a directory as argument and print all the files in it recursively as a tree."""

import sys
from os import listdir
from os.path import isfile, join

def tree(directory):
	if not isfile(directory):
		for each in listdir(directory):
			if isfile(each):
				print "|--",each
			else:
				tree(join(directory,each))
	else:
		print "|--", directory








try:
	tree(sys.argv[1])
except IndexError:
	print "Error in usage"