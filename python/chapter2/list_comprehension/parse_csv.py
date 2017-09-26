"""Write a python function parse_csv to parse csv (comma separated values) files."""

def parse_csv(filename):
	new_list = []
	for line in open(filename,"r").readlines():
		line = line.replace(',','')
		new_list.append([x for x in line.strip("\n")])
	return new_list

print parse_csv("a.csv")
