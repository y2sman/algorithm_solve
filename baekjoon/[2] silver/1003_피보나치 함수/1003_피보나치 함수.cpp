#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int T;
int N;

int dp_zero[41];
int dp_one[41];

int gogo()
{
    for(int i=2;i<=N;i++)
    {
        dp_one[i] = dp_one[i-1] + dp_one[i-2];
        dp_zero[i] = dp_one[i-1];
    }
    printf("%d %d\n",dp_zero[N],dp_one[N]);
    return 0;
}

int main()
{
    dp_zero[0] = 1;
    dp_zero[1] = 0;
    dp_one[0] = 0;
    dp_one[1] = 1;

    scanf("%d",&T);

    for(int i=0;i<T;i++)
    {
        scanf("%d",&N);
        gogo();
    }

    return 0;
}