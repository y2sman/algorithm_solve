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
#include <math.h>

using namespace std;

int N, r, c;
long long counter;

int gogo(int x, int y)
{
	if( r == y && c == x )
	{
		return 0;
	}
	else if( r == y && c == x+1 )
	{
		return 1;
	}
	else if( r == y+1 && c == x )
	{
		return 2;
	}
	else if( r == y+1 && c == x+1 )
	{
		return 3;
	}
}

void dc(int x, int y, int n)
{	
	if( n <= 2 )
	{
		counter += gogo(x,y);
		return;
	}
	
	int divider = n / 2;

	if( c < x+divider && r < y+divider )
	{
		dc(x, y, divider);
	}
	else if( c >= x+divider && r < y+divider )
	{
		counter += divider * divider;
		dc(x+divider, y, divider);
	}
	else if( c < x+divider && r >= y+divider )
	{
		counter += 2 * divider * divider;
		dc(x, y+divider, divider);
	}
	else if( c >= x+divider && r >= y+divider )
	{
		counter += 3 * divider * divider;
		dc(x+divider, y+divider, divider);
	}
}

int main()
{
	counter = 0;
	scanf("%d %d %d",&N,&r,&c);

	dc(0,0,int(pow(2,N)));
	
	printf("%lld\n",counter);
	return 0;
}
