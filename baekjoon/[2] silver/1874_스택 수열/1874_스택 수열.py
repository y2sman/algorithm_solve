n = input()

stack = list()
ans = list()
curr = 1
for i in range(int(n)):
    target = int(input())
    
    while True:
        if target >= curr:
            stack.append(curr)
            ans.append('+')
            curr += 1
        else:
            break

    if stack[-1] == target:
        stack.pop()
        ans.append('-')
    else:
        print("NO")
        break

if len(stack) == 0:
    for i in ans:
        print(i)
