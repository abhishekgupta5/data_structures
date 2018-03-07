#!/usr/bin/python3

# Question link- https://techdevguide.withgoogle.com/paths/foundational/find-longest-word-in-dictionary-that-subsequence-of-given-string#code-challenge

#Greedy approach

S = 'abppplee'
W = ['able', 'ale', 'apple', 'bale', 'kangaroo']

W.sort(key=len, reverse=True)

def find_seq(S, p):
    i = 0
    j = 0
    while (j<len(p) and i<len(S)):
        if p[j] == S[i]:
            j += 1
        i += 1
    return j==len(p)

for p in W:
    if find_seq(S, p):
        break
print(p)

#Other approaches-(see tdgwg page for detail)
#Preprocessing S to a map, and binary searching per letter in W
#Grouping words together in form of tuple(word, index matched) and processing all simultaneously
