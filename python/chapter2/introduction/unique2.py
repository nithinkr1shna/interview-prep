#unique strings in a list

def uniq(lists, key = lambda x:x):
	unique = []
	for each in lists:
		if key(each) not in unique:
			unique.append(key(each))
			

	return unique


print uniq(["python", "java", "Python", "Java"], key=lambda s: s.lower())

		

