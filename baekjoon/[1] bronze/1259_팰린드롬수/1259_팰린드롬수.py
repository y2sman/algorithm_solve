import math

while 1:
    T = input()
    
    if int(T) == 0:
        break

    upper = T[:math.floor(len(T)/2)]
    lower = T[math.ceil(len(T)/2):]
    lower = lower[::-1]

    if upper == lower:
        print("yes")
    else:
        print("no")
 