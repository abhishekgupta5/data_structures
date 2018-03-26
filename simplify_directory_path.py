#!/usr/bin/python3

def simplify(path):
    l = []
    chars = path.split('/')
    for char in chars:
        if char=='..' and l:
            l.pop()
        elif char !='..' and char !='.' and char:
            l.append(char)
    return '/'+'/'.join(l)

if __name__ == '__main__':
    #path = '/a/b/c/'
    path = '/a/./b///../../c/'
    #path = '/../'
    print(simplify(path))
