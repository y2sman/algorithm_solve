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
#include <math.h>

using namespace std;

int n;
int counter = 0;
int dp[60000];

int main()
{
  memset(dp,0,sizeof(dp));

  scanf("%d",&n);

  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 3;
  dp[4] = 1;

  for(int i=5;i<=n;i++)
  {
    vector<int> tmp;
    int index_i = sqrt(i);

    if(index_i*index_i == i)
    {
      dp[i] = 1;
    }
    else
    {
      for(int j=1;j<=index_i;j++)
      {
        tmp.push_back(dp[j*j] + dp[i-j*j]);
      }
      int min = *min_element(tmp.begin(), tmp.end());
      dp[i] = min;
    }
  }
  
  printf("%d",dp[n]);
  return 0;
}