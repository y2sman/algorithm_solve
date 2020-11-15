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

int L, R, C;

char building[31][31][31];
int visited[31][31][31];
int moving;
int flag;

tuple<int, int, int> location;
tuple<int, int, int> start_loc;
tuple<int, int, int> end_loc;

int z[6] = {1,-1,0,0,0,0};
int x[6] = {0,0,1,-1,0,0};
int y[6] = {0,0,0,0,1,-1};

void bfs()
{
    queue<pair<int, tuple<int, int, int> > > q;
    moving = 0;

    visited[get<0>(start_loc)][get<1>(start_loc)][get<2>(start_loc)] = 1;
    location = make_tuple(get<0>(start_loc),get<1>(start_loc),get<2>(start_loc));
    q.push(make_pair(moving,location));

    while(!q.empty())
    {
        moving = (q.front()).first;
        location = (q.front()).second;
        q.pop();

        if(get<0>(location) == get<0>(end_loc) && get<1>(location) == get<1>(end_loc) && get<2>(location) == get<2>(end_loc))
        {
            flag = 1;
            break;
        }
        
        for(int i=0;i<6;i++)
        {
            int loc_z = get<0>(location) + z[i];
            int loc_x = get<1>(location) + x[i];
            int loc_y = get<2>(location) + y[i];

            if(strncmp(&building[loc_z][loc_x][loc_y],"#",1) == 0)
            {
                continue;
            }

            if(loc_z < 0 || loc_x < 0 || loc_y < 0)
            {
                continue;
            }

            if(loc_z > L || loc_x > R || loc_y > C)
            {
                continue;
            }

            if(visited[loc_z][loc_x][loc_y] == 0)
            {
                visited[loc_z][loc_x][loc_y] = 1;
                tuple<int, int, int> tmp;
                tmp = make_tuple(loc_z, loc_x, loc_y);
                q.push(make_pair(moving+1,tmp));
            }
        }
    }
}

void info_input(int level)
{
    for(int i=0;i<R;i++)
    {
        scanf("%s",&building[level][i]);
        
        for(int j=0;j<strlen(building[level][i]);j++)
        {
            if(strncmp(&building[level][i][j],"S",1) == 0)
            {
                start_loc = make_tuple(level,i,j);
            }
            
            if(strncmp(&building[level][i][j],"E",1) == 0)
            {
                end_loc = make_tuple(level,i,j);
            }
        }
    }
}

int main()
{
    while(1)
    {
        scanf("%d %d %d",&L,&R,&C);
        if(L==0 && R==0 && C==0)
        {
            break;
        }

        memset(building,'#',sizeof(building));
        memset(visited,0,sizeof(visited));
       
        moving = 0;
        flag = 0;
        location = make_tuple(-1,-1,-1);
        start_loc = make_tuple(-1,-1,-1);
        end_loc = make_tuple(-1,-1,-1);

        for(int i=0;i<L;i++)
        {
            info_input(i);
        }    
        bfs();
        if(flag == 0)
        {
            printf("Trapped!\n");
        }
        else
        {
            printf("Escaped in %d minute(s).\n",moving);
        }    
    }
    
    return 0;
}
