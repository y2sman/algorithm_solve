import math

N = int(input())

stack = input().split()
stack = [int(i) for i in stack]

max_target = max(stack)
max_prime = math.sqrt(max_target)
prime_list = [False for i in range(max_target+1)]

prime_list[0] = True
prime_list[1] = True

for i in range(2, int(max_prime)+1):
    if not prime_list[i]:
        for j in range(i*i, max_target+1, i):
            prime_list[j] = True

count = 0
for i in stack:
    if not prime_list[i]:
        count += 1
        
print(count)

