import math

M, N = input().split(' ')

M = int(M)
N = int(N)

max_prime = math.sqrt(N)
prime_list = [False for i in range(N+1)]

prime_list[0] = True
prime_list[1] = True

for i in range(2, int(max_prime)+1):
    if not prime_list[i]:
        for j in range(i*i, N+1, i):
            prime_list[j] = True

for i in range(M, N+1):
    if not prime_list[i]:
        print(i)
