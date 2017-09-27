"""Write a program extcount.py to count number of files for each extension in the given directory.
 The program should take a directory name as argument and print count and extension
  for each available file extension.
  """

import sys
from os import listdir
from os.path import isfile, join

def ext_count(directory_name):
	""" returns the frequency of each exension as a dict"""
	extcount = {}
	for file in all_files(directory_name):
		file = file.split(".")
		extcount[file[1]] = extcount.get(file[1], 0) + 1

	return extcount




def all_files(directory_name):
	""" returns all files teh directory"""
	return [f for f in listdir(directory_name) if isfile(join(directory_name,f))]


#print ext_count(".")

try:
	for key, value in ext_count(sys.argv[1]).items():
		print key,":", value
except IndexError:
	print "Usage Error :python ",sys.argv[0],"directory_name"
