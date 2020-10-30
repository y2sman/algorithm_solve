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
int lion[100001];

int main()
{
    scanf("%d",&N);

    lion[1] = 3;
    lion[2] = 7;
    lion[3] = 17;

    for(int i=4;i<=N;i++)
    {
        lion[i] = (lion[i-1] * 2 + lion[i-2]) % 9901;
    }

    printf("%d", lion[N]);

    return 0;
}