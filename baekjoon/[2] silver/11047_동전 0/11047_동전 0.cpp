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

int N, K;
vector<int> coin;

int main()
{
    scanf("%d %d",&N,&K);

    for(int i=0;i<N;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        coin.push_back(tmp);
    }

    int sum = 0;
    for(int i=coin.size()-1;i>=0;i--)
    {
        sum += K / coin[i];
        K = K % coin[i];
    }
    
    printf("%d",sum);
    return 0;
}