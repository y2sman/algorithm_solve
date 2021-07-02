#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;

int N;

int map[110][110];
int visited[110][110];
bool tmp_visited[110];

void deep_search(int node)
{
  for(int i=0;i<N;i++)
  {
    if(map[node][i] == 1 && tmp_visited[i] == false)
    {
      tmp_visited[i] = true;
      deep_search(i);
    }
  }
}

void search()
{
  for(int i=0;i<N;i++)
  {
    memset(tmp_visited,false,sizeof(tmp_visited));
    deep_search(i);
    for(int j=0;j<N;j++)
    {
      if(tmp_visited[j] == true)
        visited[i][j] = 1;
    }
  }
}

int main()
{
  memset(map,0,sizeof(map));
  memset(visited,0,sizeof(visited));

  scanf("%d",&N);

  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {
      int tmp;
      scanf("%d",&tmp);
      map[i][j] = tmp;
    }
  }

  search();

  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {
      printf("%d ",visited[i][j]);
    }
    printf("\n");
  }
  return 0;
}