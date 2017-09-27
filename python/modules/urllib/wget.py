""" Write a program wget.py to download a given URL. The program should accept a URL as argument, 
download it and save it with the basename of the URL. If the URL ends with a /, consider the basename as index.html."""

import urllib
import sys

def wget(url):

	filename = "".join([c for c in url if c != "/" and c != ":" and c != "."])
	if url.endswith("/"):
		filename = filename +".html"
    

	response = urllib.urlopen(url)
	content = response.read()
	save_as_file(content, filename)

def save_as_file(content, filename):
	f = open(filename, "w+")
	for each in content:
		f.write(each)

	f.close()







try:
	wget(sys.argv[1])
except IndexError:
	print "Error in usage"