#unix commands head and tails

def head(filename):
	print "HEAD"
	count = 0;
	f = open(filename, "r")
	line = f.readline()
	while line:
		if count < 10:
			print line
			line = f.readline()
			count = count + 1
		else:
			break;

	f.close()


def tail(filename):
	print "TAIL"
	count = 0
	length = linecount(filename)
	f = open(filename, "r")
	line = f.readline()
	while line:
		if count >= length -10:
			print line
			line = f.readline()
			count = count +1
		else:

		    count = count + 1
		    line = f.readline()

	f.close()


def linecount(filename):
	return len(open(filename).readlines())

head("abc.txt")
print "\n"
tail("abc.txt")
