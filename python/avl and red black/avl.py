"""avl in python: insertion only"""


	
class Node:
	def __init__(self, value):
		self.data = value
		self.r_child = None
		self.l_child = None
		self.height = 0


def insert(root, node):
	if root is None:
		root = node
	else:
		if node.data < root.data:
			if root.l_child is None:
				root.l_child = node
			else:
				insert(root.l_child, node)
		elif node.data > root.data:
			if root.r_child is None:
				root.r_child = node
			else:
				insert(root.r_child, node)
		else:
			print "error\n",root.data

		node.height = 1+ max(height(node.l_child), node.r_child)
		balance = get_bal(node)
		# four conditions LL, LR, RR, RL

		if balance > 1: #LL or LR
			if height(node.l_child.l_child) > height(node.l_child.r_child): #LL
				return rotateright(node)
			else:
				node.l_child = rotateleft(node)
				return  rotateright(node)

		elif balance < -1:
			if height(node.r_child.r_child) > height(node.r_child.l_child): #RR
				return rotateleft(node)
			else:
				node.r_child = rotateright(node)
				return rotateleft(node)


def inorder(root):
	if root is not None:
		inorder(root.l_child)
		print root.data
		inorder(root.r_child)

def rotateright(node):
	new = node.r_child
	new2 = new.l_child

	new.l_child = node
	node.r_child = new2

	node.height =max(height(node.l_child), height(node.r_child)) +1
	new.height = max(height(new.l_child), height(new.r_child)) + 1

	return new

def rotateleft(node):
	new = node.l_child
	new2 = new.r_child

	new.r_child = node
	new.l_child = new2

	node.height = max(height(node.l_child), height(node.r_child)) + 1
	new.height = max(height(new.l_child), height(new.r_child)) + 1

	return new

def get_bal(node):
	if node is None:
		return 0
	else:
		return height(node.l_child) - height(node.r_child)

def height(node):
	if node is None:
		return 0
	else:
		return node.height

def max(a, b):
	if a > b:
		return a
	else:
		return b


r = Node(900)
for i in [1,98,45,23,9,0,12]:
	insert(r, Node(i))

inorder(r)