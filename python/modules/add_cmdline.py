#takes two numbers from command line and prints the output

import sys

def add(x, y):
  return x+y

try:
   print add(int(sys.argv[1]),int(sys.argv[2]))
except IndexError:
   print "provide two numbers as command line argments\n"
