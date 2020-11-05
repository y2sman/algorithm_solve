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
int M;
int J;
int apple[30];

int tmp;

int main()
{
    scanf("%d %d",&N,&M);
    scanf("%d",&J);

    for(int i=1;i<=J;i++)
    {
        scanf("%d",&apple[i]);
    }

    int loc = 1;
    int count = 1;

    while(1)
    {
        if(count == J + 1)
        {
            break;
        }

        if(loc <= apple[count] && apple[count] <= loc + M - 1)
        {
            count = count + 1;
        }
        else
        {
            if( apple[count] > loc )
            {
                tmp = tmp + 1;
                loc = loc + 1;
            }
            else if( apple[count] < loc )
            {
                tmp = tmp + 1;
                loc = loc - 1;     
            }
        }
        
    }

    printf("%d",tmp);

    return 0;
}