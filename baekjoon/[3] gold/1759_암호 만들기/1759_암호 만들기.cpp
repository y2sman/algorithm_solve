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

using namespace std;

int L, C;
char passwd[16];

int check_mo(char tmp)
{
    if(tmp == 'a' || tmp == 'e' || tmp == 'i' || tmp == 'o' || tmp == 'u')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void dfs(int x, int len, int mo, int ja, string tmp)
{
    if(len==L)
    {
        if(mo >= 1 && ja >= 2)
        {
            printf("%s\n",tmp.c_str());
            return;
        }
        else
        {
            return;
        }
    }

    if(x==C)
    {
        return;
    }

    if(check_mo(passwd[x]) == 1)
    {  
        dfs(x+1,len+1,mo+1,ja,tmp+passwd[x]);
    }
    else
    {
        dfs(x+1,len+1,mo,ja+1,tmp+passwd[x]);
    }

    dfs(x+1, len, mo, ja, tmp);
}

int main()
{
    scanf("%d %d",&L,&C);

    for(int i=0;i<C;i++)
    {
        scanf(" %c",&passwd[i]);
    }

    sort(passwd,passwd+C);

    string tmp;
    dfs(0,0,0,0,tmp);

    return 0;
}