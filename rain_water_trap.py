#!/usr/bin/python3

#Interviewbit-Rain water trap problem
#Question link: https://www.interviewbit.com/problems/rain-water-trapped/


#Solution using just two extra variabes
def trap(A):
    res = 0
    left_max = 0
    right_max = 0
    lo = 0
    hi = len(A)-1
    while lo<=hi:
        if A[lo]<A[hi]:
            if A[lo]>left_max:
                left_max = A[lo]
            else:
                res += left_max-A[lo]
            lo += 1
        else:
            if A[hi]>right_max:
                right_max = A[hi]
            else:
                res += right_max-A[hi]
            hi -= 1
    return res

#Solution usng two lists
def trap1(A):
    n = len(A)
    left = [0]*n
    right = [0]*n
    water = 0
    left[0] = A[0]
    right[n-1] = A[n-1]
    for i in range(1,n):
        left[i]=max(left[i-1], A[i])
    for i in range(n-2, -1, -1):
        right[i]=max(right[i+1], A[i])
    for i in range(n):
        water += min(left[i],right[i])-A[i]
    return water


#Solution using stack
def trap2(A):
    res = 0
    stack = []
    for i in range(len(A)):
        mid_height = 0
        while stack:
            [pos, height] = stack.pop()
            res += (min(height, A[i]) - mid_height) * (i - pos - 1)
            mid_height = height

            if A[i]<height:
                stack.append([pos, height])
                break
        stack.append([i, A[i]])
    return res

if __name__ == '__main__':
    l = [0,1,0,2,1,0,1,3,2,1,2,1]
    l2 = [3,0,0,2,0,4]
    print(trap(l))
