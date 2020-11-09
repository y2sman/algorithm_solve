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

using namespace std;

int N, M;
int num[100001];

int search(int tmp)
{
    int left = 0;
    int right = N-1;
    int middle = 0;
    while(left!=right)
    {
        middle = (left+right)/2;

        if(num[middle] == tmp)
        {
            return 1;
        }

        if(num[middle] > tmp)
        {
            right = middle;
        }
        else if(num[middle] < tmp)
        {
            left = middle+1;
        }
    }

    if(num[left] == tmp)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
	scanf("%d",&N);

    for(int i=0;i<N;i++)
    {
        scanf("%d",&num[i]);
    }
    sort(num, num+N);

    scanf("%d",&M);
    for(int i=0;i<M;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        printf("%d\n",search(tmp));
    }

	return 0;
} 
