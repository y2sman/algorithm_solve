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
int stage;

int moving_x[4] = {1,-1,0,0};
int moving_y[4] = {0,0,1,-1};

int visited[1001][1001];
int box[1001][1001];

queue<pair<int, pair<int, int> > > q;
pair<int, int> location;

void bfs()
{
    while(!q.empty())
    {
        stage = (q.front()).first;
        location = (q.front()).second;

        int current_x = location.first;
        int current_y = location.second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int loc_x = current_x + moving_x[i];
            int loc_y = current_y + moving_y[i];
            
            if(loc_x < 0 || loc_y < 0)
            {
                continue;
            }

            if(loc_x >= M || loc_y >= N)
            {
                continue;
            }            
            
            if(visited[loc_x][loc_y] == 0 && box[loc_x][loc_y] == 0)
            {
                visited[loc_x][loc_y] = 1;
                q.push(make_pair(stage+1, make_pair(loc_x, loc_y)));
            }  
        }
    }
}

int main()
{
    memset(visited, 0, sizeof(visited));
    memset(box, -1, sizeof(box));

    counter = 0;

    scanf("%d %d",&N,&M);

    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d", &box[i][j]);

            if(box[i][j] == 1)
            {
                visited[i][j] = 1;
                q.push(make_pair(0, make_pair(i,j)));
            }
        }
    }

    bfs();

    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(visited[i][j] == 0 && box[i][j] == 0)
            {
                printf("-1");
                return 0;
            }
        }
    }

    printf("%d",stage);
    return 0;
}