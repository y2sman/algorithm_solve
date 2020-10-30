#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N;
int chu[1001];
int sum[1001];

int ppr()
{
    for(int i=0;i<N;i++)
    {
        printf("%d ",chu[i]);
    }
    printf("\n");
}

int main()
{    
    scanf("%d",&N);
    
    for(int i=0;i<N;i++)
    {
        scanf("%d",&chu[i]);
    }
    
    sort(chu,chu+N);
    
    if(chu[0]==1)
    {
        sum[0] = 1;
        for(int i=1;i<N;i++)
        {
            sum[i] = sum[i-1] + chu[i];
            
            if(sum[i-1] + 1 < chu[i])
            {
                printf("%d",sum[i-1]+1);
                return 0;
            }
        }
    }
    else
    {
        printf("1");
        return 0;
    }
    
    printf("%d",sum[N-1]+1);
    return 0;
}