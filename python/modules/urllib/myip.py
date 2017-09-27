"""Write a program myip.py to print the external IP address of the machine. Use the response 
from http://httpbin.org/get and read the IP address from there. 
The program should print only the IP address and nothing else.
"""

import urllib
import json

def my_ip():
	response = urllib.urlopen("http://httpbin.org/get")
	content = response.read()
	data = json.loads(json.dumps(content))

	data = json.loads(data)
	return data["origin"]


print my_ip()
