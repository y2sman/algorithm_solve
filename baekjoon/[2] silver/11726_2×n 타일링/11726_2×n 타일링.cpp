#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int dp[1010];

int main()
{
    scanf("%d",&N);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 5;
    dp[5] = 8;

    for(int i=6;i<=N;i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }

    printf("%d",dp[N]);
    return 0;
}