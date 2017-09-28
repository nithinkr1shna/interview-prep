"""bank account"""


class Bank_account:

	def __init__(self):
		self.balance = 0

	def withdraw(self, amount):
		self.balance -= amount
		return self.balance

	def deposit(self, amount):
		self.balance += amount
		return self.balance



ac1 = Bank_account()
print "New Balance:",ac1.deposit(100)
print "New Balance:",ac1.withdraw(50)