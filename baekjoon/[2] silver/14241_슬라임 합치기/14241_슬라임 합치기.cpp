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
int slime[101];
int tmp;

int main()
{
    scanf("%d",&N);

    for(int i=0;i<N;i++)
    {
        scanf("%d",&slime[i]);
    }

    for(int i=0;i<N-1;i++)
    {
        tmp += slime[i] * slime[i+1];
        slime[i+1] = slime[i] + slime[i+1];
    }

    printf("%d",tmp);
    
    return 0;
}