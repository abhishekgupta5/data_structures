#!/usr/bin/python3
import collections

def concat(A, B):
    #word_dict, count_left = collections.Counter(B), len(B)
    total_length = 0
    for i in B:
        total_length += len(i)

    res_list=[]

    for i in range(len(A)-total_length+1):
        start = i
        word_start = i
        j = i+1
        word_dict, count_left = collections.Counter(B), len(B)
        #found = False
        while j<i+total_length+1:
            if A[word_start:j] in word_dict and word_dict[A[word_start:j]]>0:
                word_dict[A[word_start:j]] -= 1
                count_left -= 1
                if count_left == 0:
                    res_list.append(start)
                    break
                if word_dict[A[word_start:j]]<0:
                    break
                word_start = j
            j += 1
    return res_list



if __name__ == '__main__':
    s1 = "barfoothefoobarman"
    w1 = ("bar", "foo")

    s2 = "catbatatecatatebat"
    w2 = ("cat", "bat", "ate")

    s3 = "abcdababcd"
    w3 = ("ab", "ab", "cd")

    s4 = "abcdababcd"
    w4 = ('ab', 'ab')

    print(concat(s1, w1))
    print(concat(s2, w2))
    print(concat(s3, w3))
    print(concat(s4, w4))

