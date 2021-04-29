#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
long dp[101];

int main()
{
    scanf("%d",&N);

    for(int i=1;i<=6;i++)
    {
        dp[i] = i;
    }

    for(int i=7;i<=N;i++)
    {
        dp[i] = max({ dp[i-1] + 1, dp[i-3] * 2, dp[i-4] * 3, dp[i-5] * 4, dp[i-6] * 5, dp[i-7] * 6 });
    }

    printf("%ld",dp[N]);
    return 0;
}