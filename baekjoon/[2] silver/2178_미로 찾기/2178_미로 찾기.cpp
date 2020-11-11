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

using namespace std;

int N, M, moving;
int maze[101][101];
int visited[101][101];

queue<pair<int, pair<int, int> > > q;
pair<int, int> location;
pair<int, int> state;
int x[4] = {1,-1,0,0};
int y[4] = {0,0,1,-1};

void bfs()
{
    visited[0][0] = 1;
    moving = 0;
    location = make_pair(0,0);
    q.push(make_pair(moving,location));

    while(1)
    {
        moving = (q.front()).first;
        location = (q.front()).second;
        q.pop();

        if(location.first == N-1 && location.second == M-1)
        {
            printf("%d",moving+1);
            break;
        }
        
        for(int i=0;i<4;i++)
        {
            int loc_x = location.first + x[i];
            int loc_y = location.second + y[i];

            if(loc_x < 0 || loc_y < 0)
            {
                continue;
            }
            if(loc_x > N || loc_y > M)
            {
                continue;
            }
            if(maze[loc_x][loc_y] == 0)
            {
                continue;
            }
            if(visited[loc_x][loc_y] == 0)
            {
                visited[loc_x][loc_y] = 1;
                pair<int, int> tmp = make_pair(loc_x, loc_y);
                q.push(make_pair(moving+1,tmp));
            }  
        }
    }
}

int main()
{
    scanf("%d %d", &N,&M);
    memset(visited, 0, sizeof(visited));

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf("%1d",&maze[i][j]);
        }
    }

    bfs();

    return 0;

}