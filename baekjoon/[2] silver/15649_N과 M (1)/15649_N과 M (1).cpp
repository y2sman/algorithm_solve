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

int N, M;
int num[9];
int visited[9];

void dfs(int x)
{
    if( x == M )
    {
        for(int i=0;i<M;i++)
        {
            printf("%d ",num[i]);
        }
        printf("\n");
        return;
    }

    for(int i=1;i<=N;i++)
    {
        if(visited[i] == 0)
        {
            visited[i] = 1;
            num[x] = i;
            dfs(x+1);
            visited[i] = 0;
        }
    }
}

int main()
{
    memset(num,0,sizeof(num));
    memset(visited,0,sizeof(visited));

    scanf("%d %d",&N,&M);

    dfs(0);

    return 0;
}