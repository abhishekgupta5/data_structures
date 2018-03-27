#!/usr/bin/python3

def operate(oper, a,b):
    #a = int(a)
    #b = int(b)
    if oper == '+':
        return a+b
    elif oper == '-':
        return a-b
    elif oper == '*':
        return a*b
    else:
        return int(a/b)

def evalPostfix(exp):
    operators = ['+', '-', '*', '/']
    stack = []
    for i in range(len(exp)):
        if exp[i] not in operators:
            stack.append(int(exp[i]))
        else:
            b = stack.pop()
            a = stack.pop()
            stack.append(operate(exp[i], a, b))
    return stack.pop()

if __name__ == '__main__':
    exp = ['2', '1', '+', '3', '*']
    exp2 = ['4', '13', '5', '/', '+']
    print(evalPostfix(exp2))
