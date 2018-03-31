#!/usr/bin/python3

def multiply(A, B):
    res = [0]*(len(A)+len(B))
    for i, dig1 in enumerate(reversed(A)):
        for j, dig2 in enumerate(reversed(B)):
    #        print(res)
            res[i+j] += int(dig1)*int(dig2)
            res[i+j+1] += int(res[i+j]/10)
            res[i+j] %= 10
    #        print(res)

    while len(res)>1 and res[-1]==0:
        res.pop()
    return ''.join(str(d) for d in res[::-1])

if __name__ == '__main__':
    A="99999"
    B="99999"
    print(multiply(A, B))
