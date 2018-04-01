#!/usr/bin/python3

def longest(A):
    size = len(A)
    if size<2:
        return size
    d = {}
    d[A[0]] = 0
    res = 1
    sub = 0
    for i in range(1, size):
        if A[i] in d and sub<=d[A[i]]:
            sub = d[A[i]] + 1
        else:
            res = max(i-sub+1, res)
        d[A[i]] = i
    return res

if __name__ == '__main__':
    s1 = "abcabcbcc"
    s2 = 'aaaaaaaa'
    s3 = 'ababcabcdabcde'
    print(longest(s3))
