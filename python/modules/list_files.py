"""Write a program to list all files in the given directory.
"""

from os import listdir
from os.path import isfile, join

def list_dir():
	return [f for f in listdir(".") if isfile(join(".",f))]


for each in list_dir():
	print each




