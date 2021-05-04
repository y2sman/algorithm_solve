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
#include <set>

using namespace std;

int T;
int Q;

void gogo()
{
    multiset<int> ms;

    for(int i=0;i<Q;i++)
    {
        char command;
        int number;
        
        cin >> command >> number;

        if(command == 'I')
        {
            ms.insert(number);
        }
        else if(command == 'D')
        {
            if(ms.empty())
            {
                continue;
            }

            if(number == 1)
            {
                auto it = prev(ms.end());
                ms.erase(it);
            }
            else
            {
                auto it = ms.begin();
                ms.erase(it);
            }
        }
    }

    if(ms.empty())
    {
        printf("EMPTY\n");
    }
    else
    {
        auto front = ms.begin();
        auto end = prev(ms.end());
        printf("%d %d\n",*end,*front);
    }
}

int main()
{
    scanf("%d",&T);
    
    for(int i=0;i<T;i++)
    {
        scanf("%d",&Q);
        gogo();
    }

    return 0;
}