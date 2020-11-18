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

int w, h;
int counter;
int map[52][52];
int visited[52][52];

int x[8] = {1,-1,0,0,-1,1,-1,1};
int y[8] = {0,0,1,-1,-1,-1,1,1};


void bfs(int loc_x, int loc_y)
{
    queue<pair<int, int> > q;
    pair<int, int> location;

    visited[loc_x][loc_y] = 1;
    location = make_pair(loc_x,loc_y);
    q.push(location);

    while(!q.empty())
    {
        location = q.front();
        q.pop();
        
        for(int i=0;i<8;i++)
        {
            int tmp_x = location.first + x[i];
            int tmp_y = location.second + y[i];

            if(tmp_x < 0 || tmp_y < 0)
            {
                continue;
            }
            if(tmp_x > h || tmp_y > w)
            {
                continue;
            }
            if(map[tmp_x][tmp_y] == 0)
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

int main()
{  
    w = 1;
    h = 1;
    while(w != 0 & h != 0)
    {
        memset(map,0,sizeof(map));
        memset(visited,0,sizeof(visited));
        counter = 0;

        scanf("%d %d",&w,&h);

        if(w==0 && h==0)
        {
            break;
        }

        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                scanf("%d",&map[i][j]);
            }
        }

        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(visited[i][j] == 0 && map[i][j] == 1)
                {
                    bfs(i, j);
                    counter++;
                }            
            }
        }

        printf("%d\n",counter);
    }

    return 0;
}
