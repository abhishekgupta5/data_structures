#!/usr/bin/python3

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
    def traverse(node):
        while(node):
            print(node.value)
            node = node.next

if __name__ == '__main__':
    node1 = Node(5)
    node2 = Node(10)
    node3 = Node(15)
    node1.next = node2
    node2.next = node3
    node3.next = None
    print(Node.traverse(node1))

