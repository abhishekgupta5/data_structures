#!/usr/bin/python3

#Interviewbit-stack
#Question link: https://www.interviewbit.com/problems/redundant-braces/

def findDuplicate(string):
    stack = []
    operators = ['+', '-', '*', '/', '(']
    #Edge case- '(a)' should be True
    if len(string)==3 and '(' in string and ')' in string:
        return True
    for i in string:
        if i == ')':
            top = stack[-1]
            stack.pop()
            if top == '(':
                return True
            else:
                while top != '(' and stack:
                    top = stack[-1]
                    stack.pop()
        elif i in operators:
            stack.append(i)
    return False

if __name__ == '__main__':
    l = "(a)"
    print(findDuplicate(l))
