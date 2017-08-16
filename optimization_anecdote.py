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

#Note: f2() took 60% more time than f1() cause it comes at a cost of function call, the lambda function per list item. Fucntion call overhead in python is bigger than for loop overhead

def f3(list):
    string=""
    for element in map(str, list):
        string = string + element
    return string

#f3() clocked twice as fast as f1()
#f3() took more space than f1() as result of map is another list of the same length
#f3() contains 2 loops, for and map
#f3() is faster than f1() because in f1() str is looked up on every iteration, while in f3(), it is looked up only once, during map. Also map does it all in C

def f4(list):
    string = ""
    local_string = str
    for item in list:
        string = string + local_string(item)
    return string

#f4() is slower than f3(), but only by 25%. It was about 40% faster tahn f1(). This is because local variables lookups are faster than global or builtin variables lookups

def f6(list):
    return "".join(map(str, list))

#Join is an built-in function which is implemented in C. map is also in C. f6() ran 4-5 times faster than f3(). Moreover it doesn't have quadratic behavior like others.

