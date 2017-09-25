#lsort string based on its length

def lensort(list):
	list.sort(key = lambda x: len(x))
	return list

print lensort(["hello", "hai", "elephant", "weekly", "home"])