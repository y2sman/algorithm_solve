move_x = [1,-1,0,0]
move_y = [0,0,1,-1]

def bfs(x,y,d):
    queue = list()
    queue.append([y,x,d])

    while len(queue) != 0:
        c_x, c_y, c_d = queue[0][0], queue[0][1], queue[0][2]
        queue.pop(0)

        if map_array[c_x][c_y] == 0:
            continue

        if visited[c_x][c_y]:
            continue
        else:
            visited[c_x][c_y] = 1

            if depth_array[c_x][c_y] == -1 or depth_array[c_x][c_y] >= c_d:
                depth_array[c_x][c_y] = c_d

        for i in range(4):
            if c_x + move_x[i] < 0 or c_y + move_y[i] < 0:
                continue
            
            if c_x + move_x[i] >= n or c_y + move_y[i] >= m:
                continue
            
            queue.append([c_x + move_x[i], c_y + move_y[i], c_d+1])


n, m = map(int, input().split())

visited = list()
depth_array = list()
map_array = list()

start_x = 0
start_y = 0

for i in range(int(n)):
    tmp = list(map(int, input().split()))
    if 2 in tmp:
        start_x = [idx for idx, i in enumerate(tmp) if 2 == i][0]
        start_y = i
    map_array.append(tmp)
    visited.append([0] * len(tmp))
    depth_array.append([-1] * len(tmp))

bfs(start_x, start_y, 0)

for i in range(n):
    for j in range(m):
        if map_array[i][j] * depth_array[i][j] == 0:
            print(0, end=" ")
        else:
            print(depth_array[i][j], end=" ")
    print("")
