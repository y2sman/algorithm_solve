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

int N, K;
int counter;
int visited[300000];

void search()
{
  counter = 0;

  queue<pair<int, int> > Q;
  Q.push(make_pair(N, counter));
  visited[N] = 1;

  while(!Q.empty())
  {
    int tmp = Q.front().first;
    int stage = Q.front().second;
    Q.pop();

    if(tmp == K)
    {
      printf("%d",stage);
      return;
    }

    if(visited[tmp*2] == 0)
    {
      if(0 <= tmp*2 && tmp*2 <= 100000)
      {
        visited[tmp*2] = 1;
        Q.push(make_pair(tmp*2, stage+1));
      }
    }

    if(visited[tmp-1] == 0)
    {
      if(0 <= tmp-1 && tmp-1 <= 100000)
      {
        visited[tmp-1] = 1;
        Q.push(make_pair(tmp-1, stage+1));
      }
    }

    if(visited[tmp+1] == 0)
    {
      if(0 <= tmp+1 && tmp+1 <= 100000)
      {
        visited[tmp+1] = 1;
        Q.push(make_pair(tmp+1, stage+1));
      }
    }
  }  
}

int main()
{
  memset(visited, 0, sizeof(visited));

  scanf("%d %d",&N, &K);

  search();

  return 0;
}