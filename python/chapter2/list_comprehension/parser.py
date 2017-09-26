"""Generalize the above implementation of csv parser to support any delimiter and comments"""

def parse(filename, delimiter, comment):
	new_list = []
	for line in open(filename,"r").readlines():
		if comment in line:
			pass
		else:
			line = line.replace(delimiter,'')
			new_list.append([x for x in line.strip("\n")])

	return new_list


print parse("a.txt","!","#")