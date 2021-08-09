#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

int map[1001][1001];
int visited[1001];
int N, M, V;

void dfs()
{
  stack<int> s;
  s.push(V);

  while (!s.empty())
  {
    int mover = s.top();
    s.pop();

    if(visited[mover] == 0)
      printf("%d ", mover);
    visited[mover] = 1;

    for(int i=N;i>=0;i--)
    {
      if( map[mover][i] == 1 && visited[i] == 0)
        s.push(i);
    }
  }
  
}

void bfs()
{
  queue<int> q;
  q.push(V);

  while (!q.empty())
  {
    int mover = q.front();
    q.pop();

    if(visited[mover] == 0)
      printf("%d ", mover);
    visited[mover] = 1;

    for(int i=1;i<=N;i++)
    {
      if( map[mover][i] == 1 && visited[i] == 0)
        q.push(i);
    }
  }
  
}

int main()
{
  memset(map, 0, sizeof(map));
  memset(visited, 0, sizeof(visited));
  scanf("%d %d %d", &N,&M,&V);

  for(int i=0;i<M;i++)
  {
    int src, dst;
    scanf("%d %d",&src, &dst);

    map[src][dst] = 1;
    map[dst][src] = 1;
  }

  //DFS
  dfs();
  memset(visited, 0, sizeof(visited));
  printf("\n");
  //BFS
  bfs();

  return 0;
}