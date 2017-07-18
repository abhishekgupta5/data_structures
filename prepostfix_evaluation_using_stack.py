#!/usr/bin/python3

def operate(oper, op2, op1):
    op1 = int(op1)
    op2 = int(op2)
    if oper == '+':
        return op1+op2
    elif oper == '-':
        return op1-op2
    elif oper == '*':
        return op1*op2
    elif oper == '/':
        return op1/op2
    elif oper == '^':
        return op1**op2


def evaluateFix(exp, ch):
    operators = ['+', '-', '*', '/', '^']
    stack = []

    if ch is 1:
        for i in range(len(exp)):
            try:
                if isinstance(int(exp[i]), int):
                    stack.append(exp[i])
                    print("Pushed into stack: ", exp[i])
            except ValueError:
                if exp[i] in operators:
                    op2 = stack.pop()
                    op1 = stack.pop()
                    res = operate(exp[i], op2, op1)
                    stack.append(str(res))
                    print("Pushed into stack: ", res)
        return stack.pop()
    else:
        for i in reversed(range(len(exp))):
            try:
                if isinstance(int(exp[i]), int):
                    stack.append(exp[i])
                    print("Pushed into stack: ", exp[i])
            except ValueError:
                if exp[i] in operators:
                    op1 = stack.pop()
                    op2 = stack.pop()
                    res = operate(exp[i], op2, op1)
                    stack.append(str(res))
                    print("Pushed into stack: ", res)
        return stack.pop()

if __name__ == "__main__":
    ch = int(input("Enter postfix(1)/prefix(2)"))
    exp = list(input("Enter expression: ").split(','))
    print("Evaluation of expression is: ", evaluateFix(exp,ch))

