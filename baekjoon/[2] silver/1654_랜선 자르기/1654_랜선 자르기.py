import math

K, N = input().split()

cable = list()
for i in range(int(K)):
    cable.append(int(input()))

start = 1
end = max(cable)

result = list()
while True:
    if start > end:
        break

    mid = (start + end) // 2

    tmp = 0
    for i in range(int(K)):
        tmp = tmp + math.floor(cable[i] / mid)
    
    if tmp >= int(N):
        start = mid + 1
        result.append(mid)
    else:
        end = mid - 1

print(max(result))

'''
4 11
802
743
457
539
->200

2 4
50
200
-> 50

1 1
2
-> 2

4 18
16
16
16
16
-> 3

2 4
100
1
-> 25
'''