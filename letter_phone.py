#!/usr/bin/python3


#Interviewbit- backtracking
# Question link : https://www.interviewbit.com/problems/letter-phone/

def letterphone(digits):
    if not digits:
        return []
    d = {0: ['0'], 1: ["1"], 2: ["a", "b", "c"], 3: ["d", "e", "f"], 4: ["g", "h", "i"], 5: ["j", "k", "l"], 6: ["m", "n", "o"], 7: ["p", "q", "r", "s"], 8: ["t", "u", "v"], 9: ["w", "x", "y", "z"]}
    res = []
    for i in d[int(digits[0])]:
        for j in letterphone(digits[1:]) or [""]:
            res.append(i+j)
    return res


if __name__ == '__main__':
    digits = "27"
    print(letterphone(digits))
