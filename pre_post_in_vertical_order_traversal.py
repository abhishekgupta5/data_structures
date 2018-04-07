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

def vertical_order(root):
    from collections import defaultdict
    cols = defaultdict(list)
    queue = [(root, 0)]
    for node, i in queue:
        if node:
            cols[i].append(node.val)
            queue += (node.left, i-1), (node.right, i+1)
    print("queue", queue)
    if cols:
        return [cols[i] for i in range(min(cols.keys()), max(cols.keys()) + 1)]
    else:
        return []

if __name__ == '__main__':
    root = node(1)
    root.right = node(3)
    root.left = node(2)
    root.left.left = node(4)
    root.left.right = node(5)
    #print("Inorder traversal: ", inorder(root))
    print("Vertical order traversal: ", vertical_order(root))
