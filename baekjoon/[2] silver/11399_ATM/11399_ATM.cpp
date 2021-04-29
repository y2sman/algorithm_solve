#include <stdio.h>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>

using namespace std;

int N;

vector<pair<int, int> > num;

int main()
{
    scanf("%d",&N);

    for(int i=0;i<N;i++)
    {
        int money;
        scanf("%d",&money);

        num.push_back(make_pair(money, i));
    }

    sort(num.begin(), num.end());

    int sum = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=i;j++)
        {
            sum += num[j].first;
        }
    }

    printf("%d",sum);
    return 0;
}