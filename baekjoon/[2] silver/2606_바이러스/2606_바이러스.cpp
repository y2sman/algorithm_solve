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

int N, M;
int counter;

int graph[101][101];
int visited[101][101];
int node[101];

queue<pair<int, int> > q;
pair<int, int> location;

void bfs()
{
    visited[1][1] = 1;
    node[1] = 1;
    location = make_pair(1,1);
    q.push(location);

    while(!q.empty())
    {
        location = q.front();
        q.pop();

        if(node[location.second] != 1)
        {
            counter += 1;
            node[location.second] = 1;
        }

        for(int i=1;i<=N;i++)
        {
            if(visited[i][location.second] == 1)
            {
                continue;
            }
            if(graph[i][location.second] == 1)
            {
                visited[i][location.second] = 1;
                pair<int, int> tmp = make_pair(location.second,i);
                q.push(tmp);
            }
        }
    }
}

void ppr()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void visit_ppr()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            printf("%d ",visited[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    counter = 0;
    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));
    memset(node, 0, sizeof(node));

    scanf("%d",&N);
    scanf("%d",&M);

    for(int i=0;i<M;i++)
    {
        int source, destination;
        scanf("%d %d",&source, &destination);
        graph[source][destination] = 1;
        graph[destination][source] = 1;
    }
    
    bfs();
    ppr();
    visit_ppr();
    
    printf("%d",counter);
    return 0;
}

/*
1 
2
2 4 
4 3 

9
8
1 6
2 3
1 2
1 5
5 6
1 3
8 9
5 2

3
2
2 3
1 2

7
7
1 2
2 3
2 3
1 5
5 2
5 6
4 7
*/