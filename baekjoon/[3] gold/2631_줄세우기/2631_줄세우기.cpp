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
int child[201];
int dp[201];

int main()
{    
    scanf("%d",&N);
    
    for(int i=0;i<N;i++)
    {
        scanf("%d",&child[i]);
    }
    
    for(int i=0;i<N;i++)
    {
        dp[i] = 1;

        for(int j=0;j<i;j++)
        {
            if(child[j] < child[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }   
    }

    int max = dp[0];
    for(int i=1;i<N;i++)
    {
        if(max < dp[i])
        {
            max = dp[i];
        }
    }

    printf("%d",N-max);

    return 0;
}