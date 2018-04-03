#!/usr/bin/python3

def permutations(l):
    if len(l)==1:
        return [l]
    res = []
    for i in range(len(l)):
        #print(res)
        for j in permutations(l[:i]+l[i+1:]):
            res.append([l[i]]+j)
            #print([l[i]])
            print(j)
    return res


if __name__ == '__main__':
    l = [1,2,3]
    print(permutations(l))
