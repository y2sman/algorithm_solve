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

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > q;

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
            pair<int, int> tmp = q.top();
            if(tmp.second == 1)
            {
                printf("%d\n",tmp.first);
            }
            else
            {
                printf("-%d\n",tmp.first);
            }
            q.pop();
        }
        else
        {
            if(x > 0)
            {
                q.push(make_pair(x,1));
            }
            else
            {
                q.push(make_pair(x * -1,0));
            }
        }
    }

    return 0;
}