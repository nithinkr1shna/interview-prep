""" Write a python program zip.py to create a zip file.
 The program should take name of zip file as first argument and files to add as rest of the arguments.

 """
import sys
import zipfile



def my_zip(filename, files):
	zf = zipfile.ZipFile(filename, mode= 'w')
	for file in files:
		try:
			print "adding:",file,"to",filename
			zf.write(file)
		except:
			print "Error in writing"
	zf.close()





try: 
	my_zip(sys.argv[1], sys.argv[2:])
	
except IndexError:
	print "Usage Error"

