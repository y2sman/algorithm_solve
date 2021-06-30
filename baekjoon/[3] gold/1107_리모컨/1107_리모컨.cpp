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

int N, M;
bool numpad[10];
int dp[1000100];
int digit = 0;

bool check_remote(int num)
{
  digit = 0;
  while(1)
  {
    if(numpad[num%10] == false)
    {
      return false;
    }
    num = num / 10;
    digit++;

    if(num == 0)
    {
      break;
    }
  }

  return true;
}

void make_table()
{
  for(int i=0;i<=1000000;i++)
  {
    if(check_remote(i) == true)
    {
      dp[i] = digit;
    }
  }

  dp[99] = 1;
  dp[100] = 0;
  dp[101] = 1;
  dp[102] = 2;
}

int find_upper_lower_case()
{
  int upper = N;
  int lower = N;

  while(N<1000001)
  {
    if(dp[upper] != -1)
    {
      break;
    }
    upper++;
  }

  while(lower >= 0)
  {
    if(dp[lower] != -1)
    {
      break;
    }
    lower--;
  }

  if(lower < 0)
  {
    return dp[upper]+(upper-N);
  }
  else
  {
    return min(dp[upper]+(upper-N), dp[lower]+(N-lower));
  }
}

int main()
{
  memset(numpad,true,sizeof(numpad));
  memset(dp,-1,sizeof(dp));

  scanf("%d",&N);
  scanf("%d",&M);

  for(int i=0;i<M;i++)
  {
    int tmp;
    scanf("%d",&tmp);
    numpad[tmp] = false;
  }

  make_table();

  if(dp[N] != -1)
  {
    printf("%d",dp[N]);
  }
  else
  {
    printf("%d",find_upper_lower_case());
  }

  return 0;
}