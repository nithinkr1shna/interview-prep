"""Write a program to list all the files in the given directory 
along with their length and last modification time. 
The output should contain one line for each file containing filename,
 length and modification date separated by tabs.
"""


import sys
import os
from os import listdir
from os.path import isfile, join
from time import asctime
import datetime



def file_info(directory_name):
	""" returms a list of files with info """
	return extract_info([{file: os.stat(join(directory_name,file))} for file in all_files(directory_name) ])

def all_files(directory_name):
	""" returns all files in a directory as a list"""
	return [f for f in listdir(directory_name) if isfile(join(directory_name,f))]

def extract_info(file_info):
	""" returns a list file info"""
	return [[key,{"size": value[6], "st_atime": stamp_t_d(value[7]), "st_mtime": stamp_t_d(value[7])}] for each in file_info for key, value in each.items()]

def stamp_t_d(timestamp):
	return datetime.datetime.fromtimestamp(timestamp)


try:
	for each in file_info(sys.argv[1]):
		print each[0],"       \t","size:\t", each[1]["size"],"\tacess_time:",each[1]["st_atime"],"\tmod_time:",each[1]["st_mtime"]
except IndexError:
	print "Error in usage"