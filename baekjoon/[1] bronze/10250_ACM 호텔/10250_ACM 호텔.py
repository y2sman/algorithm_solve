import math

T = input()

for test_case in range(int(T)):
    H, W, N = input().split()


    W_result = math.ceil ( int(N) / int(H) )
    H_result = int(N) - ((W_result-1) * int(H))

    print(str(H_result)+"{:02d}".format(W_result))
