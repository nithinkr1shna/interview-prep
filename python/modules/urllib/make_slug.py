"""Write a function make_slug that takes a name converts it into a slug. A slug is a string where spaces 
and special characters are replaced by a hyphen, typically used to create blog post URL from post title. 
It should also make sure there are no more than one
 hyphen in any place and there are no hyphens at the biginning and end of the slug.
"""
import re


def make_slug(words):
	return slug_it(re.findall(r"\w+",words))

def slug_it(words):
	modified_list = []
	for each in words:
		if each != words[len(words) - 1]:
			modified_list.append(each+"-")
		else:
			modified_list.append(each)

	return "".join(modified_list)

		



print make_slug("hello worrld")
print make_slug("hello world!")
