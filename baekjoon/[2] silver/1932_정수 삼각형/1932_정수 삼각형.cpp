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
int tmp;
int triangle[501][501];
int dp[501][501];

int gogo()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<i;j++)
        {
            //Left
            if(j == 0)
            {
                dp[i][j] = triangle[i][j] + dp[i-1][j];
            }
            //Right
            else if(j == i-1)
            {
                dp[i][j] = triangle[i][j] + dp[i-1][j-1];
            }
            //Middle
            else
            {
                dp[i][j] = max(
                    triangle[i][j] + dp[i-1][j-1],
                    triangle[i][j] + dp[i-1][j]
                );
            }
        }
    }

    return 0;
}

int main()
{
    scanf("%d",&N);
    
    tmp = ((N + 1) * N ) / 2;
    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<i;j++)
        {
            scanf("%d",&triangle[i][j]);
        }
    }
    dp[0][0] = triangle[0][0];

    gogo();

    printf("%d",*max_element(dp[N],dp[N]+N));
    return 0;   
}