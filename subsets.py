#!/usr/bin/python3

def subsets(nums):
    res = [[]]
    for i in sorted(nums):
        res += [prev +[i] for prev in res]
    return sorted(res)
if __name__ == '__main__':
    s = [1,2,3]
    print(subsets(s))
