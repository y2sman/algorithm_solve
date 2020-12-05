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

int N;
int counter_white;
int counter_blue;
int paper[130][130];

int check(int x, int y, int n)
{
	int check_white = 0;
	int check_blue = 0;
	
	for(int i=x;i<x+n;i++)
	{
		for(int j=y;j<y+n;j++)
		{
			if(paper[i][j] == 0)
			{
				check_white++;
			}
			if(paper[i][j] == 1)
			{
				check_blue++;
			}
		}
	}
	
	if(check_white == n * n)
	{
		counter_white++;
		return 1;
	}
	
	if(check_blue == n * n)
	{
		counter_blue++;
		return 1;
	}
	
	return 0;
}

void dc(int x, int y, int n)
{
	if(check(x, y, n) == 0)
	{
		dc(x, y, n/2);
		dc(x, y+n/2, n/2);
		dc(x+n/2, y, n/2);
		dc(x+n/2, y+n/2, n/2);
	}
}

int main()
{
	counter_white = 0;
	counter_blue = 0;
	memset(paper, -1, sizeof(paper));
	
	scanf("%d",&N);
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&paper[i][j]);
		}
	}

	dc(0,0,N);
	
	printf("%d\n",counter_white);
	printf("%d\n",counter_blue);
	
	return 0;
}
