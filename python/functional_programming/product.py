"""
Implement a function product to multiply 2 numbers recursively using + and - operators only.
"""

def product(num1, num2):
	if num1 < num2:
		return product(num2, num1)
	elif num2 != 0:
		return num1 + product(num1, num2-1)
	else:
		return 0


print product(2,3)