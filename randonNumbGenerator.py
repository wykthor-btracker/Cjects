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
def addNumbers(size):
	with open("input.dat","a") as f:
		x = []
		for i in range(size):
			x.append(randint(1,i+1))
		for i in range(len(x)):
			x[i] = str(x[i])
		b = " ".join(x)
		b = b+"\n"
		f.write(b)
#main
def main():
	addNumbers(int(argv[1]))
	return 0

if __name__ == '__main__':
	main()
#main#
