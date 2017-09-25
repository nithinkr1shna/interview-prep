# factorial function // recursive implementation

def fac(num):
	if num <= 1:
		return 1
	else:
		return num * fac(num -1)

print fac(5)