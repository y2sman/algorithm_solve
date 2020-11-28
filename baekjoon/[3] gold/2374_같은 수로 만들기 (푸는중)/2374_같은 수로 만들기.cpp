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
long long counter;

vector<long long> number;

int main()
{
	counter = 0;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        long long tmp;
        scanf("%lld",&tmp);

		if(i == 0)
		{
			number.push_back(tmp);
		}
		
		if(i != 0 && number.back() != tmp)
		{
			number.push_back(tmp);
		}
    }

	while(number.size() != 1)
	{
		//printf("DBG[%d] : %lld <-> %lld\n",number.size(),number[0],number[1]);
		vector<long long>::iterator iter = number.begin();

		if(number[0] == number[1])
		{
			number.erase(iter);
		}
		else if(number[0] > number[1])
		{
			counter += number[0] - number[1];
			number.erase(iter+1);
		}
		else
		{
			counter += number[1] - number[0];
			number.erase(iter);
		}
	}
	
	printf("%lld",counter);

    return 0;
}

/*
45
1
1000000000
1
1000000000
1
1000000000
1
1000000000
1
1000000000
1
1000000000
1
1000000000
1
1000000000
1
1000000000
1
1000000000
1
1000000000
1
1000000000
1
1000000000
1
1000000000
1
1000000000
1
1000000000
1
1000000000
1
1000000000
1
1000000000
1
1000000000
1
1000000000
1
1000000000
1

6
1 1 2 1 2 1

18446744073709551615
10000000000000000000000000
9223372036854775807
18446744073709551615

2,147,483,647
1,000,000,000
*/
