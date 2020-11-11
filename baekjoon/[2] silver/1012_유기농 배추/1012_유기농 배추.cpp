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

int T, N, M, K, moving, counter;
int farm[51][51];
int visited[51][51];

queue<pair<int, int> > q;
pair<int, int> location;
pair<int, int> state;
int x[4] = {1,-1,0,0};
int y[4] = {0,0,1,-1};

void bfs(int loc_x, int loc_y)
{
    visited[loc_x][loc_y] = 1;
    location = make_pair(loc_x,loc_y);
    q.push(location);

    while(!q.empty())
    {
        location = q.front();
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            int tmp_x = location.first + x[i];
            int tmp_y = location.second + y[i];

            if(tmp_x < 0 || tmp_y < 0)
            {
                continue;
            }
            if(tmp_x > N || tmp_y > M)
            {
                continue;
            }
            if(farm[tmp_x][tmp_y] == 0)
            {
                continue;
            }
            if(visited[tmp_x][tmp_y] == 0)
            {
                visited[tmp_x][tmp_y] = 1;
                pair<int, int> tmp = make_pair(tmp_x, tmp_y);
                q.push(tmp);
            }  
        }
    }   
}

void gogo()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(visited[i][j] == 0 && farm[i][j] == 1)
            {
                bfs(i, j);
                counter++;
            }
        }
    }
}

int main()
{
    scanf("%d",&T);

    for(int i=0;i<T;i++)
    {
        scanf("%d %d %d",&N,&M,&K);
        memset(farm, 0, sizeof(farm));
        memset(visited, 0, sizeof(visited));
        
        int tmp_x, tmp_y;
        for(int j=0;j<K;j++)
        {
            scanf("%d %d",&tmp_x,&tmp_y);
            farm[tmp_x][tmp_y] = 1;
        }
        gogo();
        printf("%d\n",counter);
        counter = 0;
    }

    return 0;

}