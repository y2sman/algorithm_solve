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

int N;

int main()
{
  scanf("%d",&N);

  int five = 0;
  int two = 0;

  for(int i=5;i<=N;i=i+5)
  {
    int tmp = i;
    
    while (tmp % 5 == 0)
    {
      if(tmp % 5 == 0)
      {
        five++;
        tmp /= 5;
      }
    }
  }

  printf("%d",five);
  return 0;
}