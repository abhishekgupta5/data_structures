#!/usr/bin/python3
from functools import reduce
#Convert a list of integers to string

def f1(list):
    string = ""
    for item in list:
        string = string + str(item)
    return string

def f2(list):
    return reduce(lambda string, item: string + str(item), list, "")

#Note: f2 is slower than f1 cause it comes at a cost of function call, the lambda function per list item. Fucntion call overhead in python is bigger than for loop overhead
