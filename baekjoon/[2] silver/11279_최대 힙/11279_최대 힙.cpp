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

priority_queue<int> q;

int main()
{
    scanf("%d",&N);

    for(int i=0;i<N;i++)
    {
        int x;
        scanf("%d",&x);

        if(q.empty() && x == 0)
        {
            printf("0\n");
        }
        else if(x==0)
        {
            int tmp = q.top();
            printf("%d\n",tmp);
            q.pop();
        }
        else
        {
            q.push(x);
        }
    }

    return 0;
}