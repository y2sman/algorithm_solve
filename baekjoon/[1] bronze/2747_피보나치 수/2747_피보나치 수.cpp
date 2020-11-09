#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;
int fibo[50];

int main()
{
    scanf("%d",&n);
    
    fibo[0] = 0;
    fibo[1] = 1;
    fibo[2] = 1;
    fibo[3] = 2;

    for(int i=4;i<=n;i++)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    printf("%d",fibo[n]);
    return 0;
}