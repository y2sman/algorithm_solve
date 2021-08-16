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

int N;
int map[110][110];
int visited[110][110];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void search(int x, int y, bool switcher)
{
  queue<pair<int, int> > q;
  q.push(make_pair(x,y));
  int color = map[x][y];

  if(switcher)
  {
    color = (color + 1) % 3 % 2;
  }

  while (!q.empty())
  {
    pair<int, int> cur = q.front();
    q.pop();

    for(int i=0;i<4;i++)
    {
      int loc_x = cur.first + dx[i];
      int loc_y = cur.second + dy[i];

      if(loc_x >= 0 && loc_y >= 0 && loc_x < N && loc_y < N)
      {
        int tmp = map[loc_x][loc_y];
        if(switcher)
        {
          tmp = (map[loc_x][loc_y] + 1) % 3 % 2;
        }

        if(visited[loc_x][loc_y] == 0 && tmp == color)
        {
          visited[loc_x][loc_y] = 1;
          q.push(make_pair(loc_x,loc_y));
        }      
      }
    }
  }
}

int main()
{
  memset(map,0,sizeof(map));
  memset(visited,0,sizeof(visited));

  scanf("%d ",&N);

  for(int i=0;i<N;i++)
  {
    char tmp[110];
    scanf("%s",&tmp);
    for(int j=0;j<N;j++)
    {
      // R 82 G 71 B 66
      map[j][i] = tmp[j];
    }
  }
  
  int counter = 0;
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {
      if(visited[i][j] == 0)
      {
        search(i,j,false);
        counter++;
      }
    }
  }

  memset(visited,0,sizeof(visited));
  int problem_counter = 0;
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {
      if(visited[i][j] == 0)
      {
        search(i,j,true);
        problem_counter++;
      }
    }
  }
  printf("%d %d",counter,problem_counter);
  return 0;
}
