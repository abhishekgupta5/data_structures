#!/usr/bin/python3

#Interviewbit-LinkedList
#Question link: https://www.interviewbit.com/problems/partition-list/
class ListNode:
    def __init__(self,x):
        self.val = x
        self.next = None
    def traverse(node):
        while(node):
            print(node.val, end=' ')
            node=node.next

def partition(A, B):
    start_small, start_large = ListNode(-1), ListNode(-1)
    end_small, end_large = start_small, start_large
    temp = A
    while temp:
        if (temp.val<B):
            end_small.next = temp
            end_small = temp
        else:
            end_large.next = temp
            end_large = temp
            temp=temp.next
        end_small.next = start_large.next
        end_large.next = None
        return start_small.next
if __name__ == '__main__':
    a1 = ListNode(1)
    a2 = ListNode(4)
    a3 = ListNode(3)
    a4 = ListNode(2)
    a5 = ListNode(5)
    a6 = ListNode(2)
    a1.next = a2
    a2.next = a3
    a3.next = a4
    a4.next = a5
    a5.next = a6
    a6.next = None
    ans = partition(a1, 3)
    ListNode.traverse(ans)
