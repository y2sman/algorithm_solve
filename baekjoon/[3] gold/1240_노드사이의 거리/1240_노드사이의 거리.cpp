#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
int graph[1001][1001];
int visited[1001];

void bfs(int source, int dest)
{
    queue<pair<int, int> > q;
    pair<int, int> location = make_pair(source, 0);
    visited[source] = 1;
    q.push(location);

    while(!q.empty())
    {
        location = q.front();
        q.pop();

        if(location.first == dest)
        {
            printf("%d\n", location.second);
            break;
        }

        for(int i=1;i<=N;i++)
        {
            if(visited[i] == 1)
            {
                continue;
            }
            if(graph[i][location.first] != 0)
            {
                visited[i] = 1;
                pair<int, int> tmp = make_pair(i, graph[i][location.first] + location.second);
                q.push(tmp);
            }
        }
    }
}

int main()
{
    memset(graph,0,sizeof(graph));

    scanf("%d %d",&N,&M);

    for(int i=0;i<N-1;i++)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        graph[x][y] = z;
        graph[y][x] = z;
    }

    for(int i=0;i<M;i++)
    {
        int x, y;
        memset(visited,0,sizeof(visited));

        scanf("%d %d",&x,&y);
        bfs(x,y);
    }

    return 0;
}