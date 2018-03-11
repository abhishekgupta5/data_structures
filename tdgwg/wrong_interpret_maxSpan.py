#!/usr/bin/python3

#Question link: http://codingbat.com/prob/p189576

#Solution
#[Update] Wrong interpretation of question, this is not maxSpan

def function(A):
    sum_list = []
    size = len(A)
    count = 0
    for i,j in zip(A, reversed(A)):
        if (count == int(size/2)):
            break
        sum_list.append(i+j)
        count += 1
    return max(max(sum_list), A[int(size/2)])

if __name__ == '__main__':
    print("Enter list(space separated integer values): ")
    lis = [int(x) for x in input().split()]
    print(function(lis))
