#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#fileheader
#imports
from sys import argv
from random import randint
#variables

#classes

#functions

#main
def main():
	with open("input.dat","w") as f:
		x = ''
		for i in range(int(argv[1])):
			x = x+' '+str(randint(1,int(argv[1])))
		f.write(x)
	return 0

if __name__ == '__main__':
	main()
#main#
