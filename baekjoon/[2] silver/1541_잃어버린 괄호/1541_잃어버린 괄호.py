import re

tmp = input()

result = re.split('[+-]',tmp)

locate = 1
for i in range(len(tmp)):
  if tmp[i] == "+":
    result.insert(locate,tmp[i])
    locate += 2
  elif tmp[i] == "-":
    result.insert(locate,tmp[i])
    locate += 2

locate = 0
while "+" in result:
  if result[locate] == "+":
    tmp = int(result[locate-1]) + int(result[locate+1])
    result.pop(locate-1)
    result.pop(locate-1)
    result.pop(locate-1)
    result.insert(locate-1, tmp)
  else:  
    locate += 1
    if locate == len(result):
      locate = 0

locate = 0
while "-" in result:
  if result[locate] == "-":
    tmp = int(result[locate-1]) - int(result[locate+1])
    result.pop(locate-1)
    result.pop(locate-1)
    result.pop(locate-1)
    result.insert(locate-1, tmp)
  else:  
    locate += 1
    if locate == len(result):
      locate = 0

print(result[0])
