"""Write a program links.py 
that takes URL of a webpage as argument and prints all the URLs linked from that webpage.
"""

import sys
import urllib
import re

def links(address):
	response = urllib.urlopen(address)
	content = response.read()
	all_links = re.findall(r"<a.*?\s*href=\"(.*?)\".*?>(>*?)</a>",content)
	for links in all_links:
		if "https" or "http" in links[0]:
			print links[0]





try:
	links(sys.argv[1])
except IndexError:
	print "Usage Error"