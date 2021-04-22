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
#include <string>

using namespace std;

int main()
{
    int A, B, C;

    scanf("%d %d %d",&A, &B, &C);

    int tmp = A * B * C;
    string number = to_string(tmp);

    vector<int> counter[10];

    for(int i=0;i<number.length();i++)
    {
        int iter = tmp % 10;
        tmp /= 10;

        counter[iter].push_back(iter);
    }

    for(int i=0;i<10;i++)
    {
        printf("%d\n", counter[i].size());
    }

    return 0;
}