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
#include <tuple>
#include <numeric>

using namespace std;

vector<int> number;

int main()
{
    int N, M;

    scanf("%d %d",&N,&M);

    for(int i=0;i<N;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        number.push_back(tmp);
    }

    vector<int> sum(number.size());
    partial_sum(number.begin(), number.end(), sum.begin());

    for(int i=0;i<M;i++)
    {
        int x, y;
        scanf("%d %d",&x,&y);

        if(x==1)
        {
            printf("%d\n", sum[y-1]);
        }
        else
        {
            printf("%d\n", sum[y-1]-sum[x-2]);
        }
    }

    return 0;
}