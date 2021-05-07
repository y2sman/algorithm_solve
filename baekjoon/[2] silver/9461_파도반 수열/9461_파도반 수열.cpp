#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <tuple>

using namespace std;

long long dp[110];

int main()
{
    int T;

    scanf("%d",&T);

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    dp[6] = 3;

    for(int i=7;i<=102;i++)
    {
        dp[i] = dp[i-1] + dp[i-5];
    }

    for(int i=0;i<T;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        printf("%lld\n",dp[tmp]);
    }

    return 0;
}