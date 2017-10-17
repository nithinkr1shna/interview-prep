""" red balck tree : insertion only"""

class Node:
	def __init__(self, data):
		self.data = data
		self.right = None
		self.left = None
		self.parent = None
		self.color = 'r'


def BSTinsert(root, node):
	if root is None:
		return node
	elif node.data < root.data:
		root.left = BSTinsert(root.left, node)
		root.left.parent = root
	elif node.data > root.data:
		root.right = BSTinsert(root.right, node)
		root.right.parent = root

	return root



def insert(data, root):
	node = Node(data)
	root = BSTinsert(root,node)
	fixviolation(root,node)
	

def fixviolation(root, node):
	
	while node is not None and node.color is not 'b' and node.parent.color is 'r':
		parent_pt = node.parent
		

		#twek grand_parent_pt = node.parent.parent to node.parent
		grand_parent_pt = node.parent.parent

		#case A:
		# parent of node is left child of grand_parent of node
		if parent_pt == grand_parent_pt.right:
			uncle_pt = grand_parent_pt.right

			#case 1
			# the uncle of node is also red
			# only recoloring is required
			if uncle_pt is not None and uncle_pt.color == 'r':
				grand_parent_pt.color = 'r'
				parent_pt.color = 'b'
				uncle_pt.color = 'b'
				node = grand_parent_pt
			else:
				#case 2
				# node is right child of its parent
				# Lrot s required
				if node == parent_pt.right:
					rotateRight(root, grand_parent_pt)
					swapcolor(parent_pt, grand_parent_pt)
					node = parent_pt

		else:
			# case B
			# parent of node is right child of grand-parent of node
			uncle_pt = grand_parent_pt.left
			# case 1
			# the uncle of node is also red
			# only require recoloring
			if uncle_pt is not None and uncle_pt.color == 'r':
				grand_parent_pt.color = 'r'
				parent_pt.color = 'b'
				uncle_pt.color = 'b'
				node = grand_parent_pt
			else:
				# case 2
				# node is left child of its parent
				# right rot is req
				if node == parent_pt.left:
					rotateRight(root, parent_pt)
					node = parent_pt
					parent_pt = node.parent;

				rotateLeft(root, grand_parent_pt)
				swapcolor(parent_pt, grand_parent_pt)
				node = parent_pt

	root.color = 'b'



def rotateLeft(root, node):
	pt_right = node.right
	pt_right = pt_right.left

	if node.right is not None:
		node.right.parent = node
	pt_right.parent = pt.parent_pt

	if node.parent is None:
		root = pt_right
	elif node == node.parent.left:
		node.parent.left = node.right
	else:
		node.parent.right = node.right

	pt_right.left =node
	node.parent_pt = pt_right



def rotateRight(root, pt):

	pt_left = pt.left
	pt.left = pt_left.right

	if pt.left is not None:
		pt.left.parent =pt
	pt_left.parent = pt.parent

	if pt.parent is None:
		root = pt_left

	elif pt == pt.parent.left:
		pt.parent.left = pt_left
	else:
		pt.parent.right = pt_left

	pt_left.right = pt
	pt.parent = pt_left


def swapcolor(parent_pt, grand_parent_pt):
	parent_pt.color, grand_parent_pt.color = grand_parent_pt.color, parent_pt.color


def inorder(root):
	if root is not None:
		inorder(root.left)
		print root.data, root.parent, root.color
		inorder(root.right)




r = Node(100)
numbers = [7,6,5,4,3,2,1]
for i in numbers:
	insert(i,r)

inorder(r)