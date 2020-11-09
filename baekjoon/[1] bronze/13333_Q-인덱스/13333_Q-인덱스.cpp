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

int n;
int k;
int tmp;
int counter = 0;

vector <int> list;

int main()
{
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		list.push_back(tmp);
	}

	sort(list.begin(), list.end());	

	for(int i=n;i>=0;i--)
	{
		if(list[n-i] >= i)
		{
			printf("%d",i);
			break;
		}
	}
	
	return 0;
} 