#!/usr/bin/python3

def smallerNearest(s):
    stack = []
    res = []
    for i in range(len(s)):
        while stack and stack[-1]>=s[i]:
            stack.pop()
        if not stack:
            res.append(-1)
        else:
            res.append(stack[-1])
        stack.append(s[i])
    return res

if __name__ == '__main__':
    #l = [1,6,4,10,2,5]
    #l = [1,3,0,2,5]
    #l = [4,5,2,10,8]
    l = [3,2,1]
    print(smallerNearest(l))
