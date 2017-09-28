"""
min balance account
"""


class Bank_account:

	def __init__(self):
		self.balace = 0

	def withdraw(self, amount):
		self.balance -= amount
		return self.balance

	def deposit(self, amount):
		self.deposit += amount
		return self.balance

class Min_account(Bank_account):

	def __init__(self, min_balace):
		Bank_account.__init__(self)
		self.min_balace = min_balace

	def withdraw(self, amount):
		if self.balance - amount < self.min_balace:
			print "sorry min bal must be amintained"
		else:
			Bank_account.withdraw(self,amount)