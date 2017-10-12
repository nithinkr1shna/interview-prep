"""bst an implementation: insertion only """



class Node:
	"""creates an object with attributes data, rightchild and leftchild """
	def __init__(self, value):
		self.data = value
		self.r_child = None
		self.l_child = None


def insert(root, node):
	"""Takes argumnets the root of the tree and the node
	   adds the new node to the tree acc to the bst 
	   property
	"""
	if root is None:
		root = node
	else:
		if root.data > node.data:
			if root.l_child is None:
				root.l_child = node
			else:
				insert(root.l_child, node)
		elif root.data < node.data:
			if root.r_child is None:
				root.r_child = node
			else:
				insert(root.r_child, node)
		else:
			print "Error"

def inorder(root):
	"""for inorder tree traversal"""
	if root is not None:
		inorder(root.l_child)
		print root.data
		inorder(root.r_child)



root = Node(100)
for i in xrange(10):
	insert(root, Node(i))

inorder(root)




