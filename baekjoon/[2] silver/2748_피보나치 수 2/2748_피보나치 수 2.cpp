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

int N,M;

long long num[1000000];

int main()
{
	scanf("%d",&N);

	num[0] = 0;
	num[1] = 1;

	for(int i=2;i<=N;i++)
	{
		num[i] = num[i-1] + num[i-2];
	}
	
	printf("%lld\n",num[N]);
  
	return 0;
} 
