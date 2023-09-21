def convert_map_bin(x, y):
    return_map = list()
    for m in range(len(x)):
        output = int(''.join(x[m][y:y+8]), 2)
        return_map.append(output)
    return return_map

def check_map(map):
    pattern_A = list()
    pattern_A.append(list(bin(map[0] ^ correct_map_A)[2:]).count('1'))
    pattern_A.append(list(bin(map[1] ^ correct_map_B)[2:]).count('1'))
    pattern_A.append(list(bin(map[2] ^ correct_map_A)[2:]).count('1'))
    pattern_A.append(list(bin(map[3] ^ correct_map_B)[2:]).count('1'))
    pattern_A.append(list(bin(map[4] ^ correct_map_A)[2:]).count('1'))
    pattern_A.append(list(bin(map[5] ^ correct_map_B)[2:]).count('1'))
    pattern_A.append(list(bin(map[6] ^ correct_map_A)[2:]).count('1'))
    pattern_A.append(list(bin(map[7] ^ correct_map_B)[2:]).count('1'))

    pattern_B = list()
    pattern_B.append(list(bin(map[0] ^ correct_map_B)[2:]).count('1'))
    pattern_B.append(list(bin(map[1] ^ correct_map_A)[2:]).count('1'))
    pattern_B.append(list(bin(map[2] ^ correct_map_B)[2:]).count('1'))
    pattern_B.append(list(bin(map[3] ^ correct_map_A)[2:]).count('1'))
    pattern_B.append(list(bin(map[4] ^ correct_map_B)[2:]).count('1'))
    pattern_B.append(list(bin(map[5] ^ correct_map_A)[2:]).count('1'))
    pattern_B.append(list(bin(map[6] ^ correct_map_B)[2:]).count('1'))
    pattern_B.append(list(bin(map[7] ^ correct_map_A)[2:]).count('1'))
    return sum(pattern_A), sum(pattern_B)

M, N = input().split()

map = list()
for i in range(int(M)):
    tmp = input()
    tmp = ['0' if i == 'W' else '1' for i in tmp]
    map.append(tmp)


correct_map_A = 0b01010101
correct_map_B = 0b10101010

result = list()
for i in range(int(M)-7):
    for j in range(int(N)-7):
        tmp_map = map[i:i+8]
        tmp_map = convert_map_bin(tmp_map, j)

        map_result_A, map_result_B = check_map(tmp_map)
        if map_result_A > map_result_B:
            result.append(map_result_B)
        else:
            result.append(map_result_A)
print(min(result))

'''
10 13
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
WWWWWWWWWWBWB
WWWWWWWWWWBWB

12
'''