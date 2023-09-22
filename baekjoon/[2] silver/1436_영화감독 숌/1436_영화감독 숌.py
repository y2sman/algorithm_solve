N = input()
target = '666'

count = 0
idx = 0
while True:
    if target in str(idx):
        count += 1
    
    if count == int(N):
        break

    idx += 1
    
print(idx)