#!/usr/bin/python3

#Iterative techniques for inorder, preorder, postorder traversal in BT

class node:
    def __init__(self, x):
        self.val=x
        self.left=None
        self.right=None

def inorder(root):
    res = []
    stack = [(root, False)]
    while stack:
        root, is_visited = stack.pop()
        if root is None:
            continue
        if is_visited:
            res.append(root.val)
        else:
            stack.append((root, True))
            stack.append((root.right, False))
            stack.append((root.left, False))
    return res

if __name__ == '__main__':
    root = node(1)
    root.right = node(3)
    root.left = node(2)
    root.left.left = node(4)
    root.left.right = node(5)
    print("Inorder traversal: ", inorder(root))
