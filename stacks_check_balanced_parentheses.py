#!/usr/bin/python3

#Code for checking balanced parentheses using stack.

def brackets_paired(top, element_in_string):
    if top == '{' and element_in_string == '}':
        return True
    if top == '[' and element_in_string == ']':
        return True
    if top == '(' and element_in_string == ')':
        return True
    return False


def check_balanced_parentheses(exp):
    stack=[]
    opening_pars = ['{', '[', '(']
    closing_pars = ['}', ']', ')']
    for i in range(len(exp)):
        if exp[i] in opening_pars:
            stack.append(exp[i])
        elif exp[i] in closing_pars:
            if len(stack) == 0:
                return False
            top = stack.pop()
            stack.append(top)
            if not brackets_paired(top, exp[i]):
                return False
            else:
                stack.pop()
    if len(stack) == 0:
        return True
    else:
        return False

if __name__ == '__main__':
    exp = str(input())
    if check_balanced_parentheses(exp):
        print("Balanced.")
    else:
        print("Not balanced.")


