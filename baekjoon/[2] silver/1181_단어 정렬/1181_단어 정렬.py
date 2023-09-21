import string
import os

N = input()

word_list = dict()
call_list = list()

for i in range(int(N)):
    tmp = input()
    try:
        word_list[len(tmp)].append(tmp)
    except:
        word_list[len(tmp)] = [tmp]
    call_list.append(len(tmp))

for i in sorted(list(set(call_list))):
    for j in sorted(list(set(word_list[i]))):
        print(j)
