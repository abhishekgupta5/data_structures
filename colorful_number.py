#!/usr/bin/python3
from functools import reduce

def colorful(A):
    A = str(A)
    s = set()
    for i in range(len(A)):
        for j in range(i+1, len(A)+1):
            x = reduce(lambda x, y: x*y, map(int, A[i:j])
            print(x)
            if x in s:
                return False
            else:
                s.add(x)
    return True

if __name__ == '__main__':
    num = '3245'
    print(colorful(num))
