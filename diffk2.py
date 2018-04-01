#!/usr/bin/python3

def diffk(A, B):
    s = set(A)
    if len(A)<2:
        return 0
    if len(s)==len(A) and B==0:
        return 0
    for i in A:
        if i+B in s:
            return 1
    return 0


if __name__ == '__main__':
    A = [1,2,3]
    B = 0
    print(diffk(A, B))
