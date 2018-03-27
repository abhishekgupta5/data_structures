#!/usr/bin/python3

#Interviewbit-MinStack
#Question link-

#O(1) Time and O(1) Space for all functions

class MinStack:
    def __init__(self):
        self.stack = []
        self.minElem = 0

    def getMin(self):
        if self.stack:
            return self.minElem
        return -1

    def top(self):
        if not self.stack:
            return -1
        elif self.stack[-1]<self.minElem:
            return self.minElem
        else:
            return self.stack[-1]
    def pop(self):
        if not self.stack:
            return
        top = self.stack[-1]
        self.stack.pop()
        if top<self.minElem:
            tempMin = self.minElem
            self.minElem = 2*self.minElem-top
            return tempMin
        else:
            return top
    def push(self, x):
        if not self.stack:
            self.stack.append(x)
            self.minElem = x
        if x<self.minElem:
            self.stack.append(2*x-self.minElem)
            self.minElem = x
        else:
            self.stack.append(x)
if __name__ == '__main__':
    stack1 = MinStack()
    #print(stack1.getMin())
    stack1.push(2)
    #print(stack1.top())
    stack1.push(3)
    #print(stack1.top())
    stack1.push(10)
    #print(stack1.top())
    print(stack1.getMin())
    stack1.push(1)
    print(stack1.getMin())
    #print(stack1.pop())
    stack1.push(240)
    #print(stack1.pop())

