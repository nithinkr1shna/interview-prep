# extension sort


def extsort(list):
	d = dict()
	for each in list:
		var = each.split(".")
		d[var[1]] =var[0]

	
	return [".".join([d[key], key]) for key in sorted(d.keys()) ]

	



print extsort(["a.c", "a.e", "file.xls", "file.exe", "list.txt"])