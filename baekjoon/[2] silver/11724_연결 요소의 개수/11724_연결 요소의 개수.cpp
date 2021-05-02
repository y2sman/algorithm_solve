#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>

using namespace std;

int N, M;
int counter;

bool visited[1001][1001];
bool map[1001][1001];
bool node[1001];

void bfs(int x)
{
    node[x] = true;

    for(int i=1;i<=N;i++)
    {
        if(map[x][i] == true && node[i] != true)
        {
            bfs(i);
        }
    }
}

int main()
{
    memset(map, false, sizeof(map));
    memset(visited, false, sizeof(visited));
    memset(node, false, sizeof(node));

    counter = 0;

    scanf("%d %d",&N,&M);

    for(int i=0;i<M;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);

        map[x][y] = true;
        map[y][x] = true;
    }

    for(int i=1;i<=N;i++)
    {
        if(node[i] != true)
        {
            counter++;
            bfs(i);
        }
    }

    /*
    for(int i=1;i<=N;i++)
    {
        printf("%d ",node[i]);
    }
    */

    printf("%d",counter);
    return 0;
}

/*
3 1
1 2
-> 2

6 2
3 4
4 2
-> 4
*/