#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <tuple>

using namespace std;

int N, M, H;
int stage;

int moving_z[6] = {1,-1,0,0,0,0};
int moving_x[6] = {0,0,1,-1,0,0};
int moving_y[6] = {0,0,0,0,1,-1};

int visited[110][110][110];
int box[110][110][110];

priority_queue<pair<int, tuple<int, int, int> >, vector<pair<int, tuple<int, int, int> >>, greater<> > q;
tuple<int, int, int> location;

void bfs()
{
    while(!q.empty())
    {
        stage = (q.top()).first;
        location = (q.top()).second;

        int current_z = get<0>(location);
        int current_x = get<1>(location);
        int current_y = get<2>(location);

        q.pop();

        for(int i=0;i<6;i++)
        {
            int loc_z = current_z + moving_z[i];
            int loc_x = current_x + moving_x[i];
            int loc_y = current_y + moving_y[i];
            
            if(loc_z < 0 || loc_x < 0 || loc_y < 0)
            {
                continue;
            }

            if(loc_z >= H || loc_x >= M || loc_y >= N)
            {
                continue;
            }
            
            if(visited[loc_z][loc_x][loc_y] == 1)
            {
                continue;
            }

            if(visited[loc_z][loc_x][loc_y] == 0 && box[loc_z][loc_x][loc_y] != -1)
            {
                visited[loc_z][loc_x][loc_y] = 1;
                q.push(make_pair(stage+1, make_tuple(loc_z, loc_x, loc_y)));
            }
        }
    }
}

void tomato_input(int level)
{
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d", &box[level][i][j]);

            if(box[level][i][j] == 1)
            {
                visited[level][i][j] = 1;
                q.push(make_pair(0, make_tuple(level,i,j)));
            }
        }
    }
}

int gogo(int level)
{
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(visited[level][i][j] == 0 && box[level][i][j] == 0)
            {
                printf("-1");
                return -1;
            }
        }
    }
    return 1;
}

int main()
{
    memset(visited, 0, sizeof(visited));
    memset(box, -1, sizeof(box));

    scanf("%d %d %d",&N,&M,&H);

    for(int i=0;i<H;i++)
    {
        tomato_input(i);
    }

    bfs();

    for(int i=0;i<H;i++)
    {
        if(gogo(i) == -1)
        {
            return 0;
        }
    }

    printf("%d",stage);
    return 0;
}
