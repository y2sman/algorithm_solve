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

int main()
{
  int N = 0;
  int score = 0;
  char tmp[200];

  scanf("%d ", &N);

  for(int i=0;i<N;i++)
  {
    scanf("%c",&tmp[i]);
    score += tmp[i] - 48;

  }

  printf("%d",score);
  return 0;
}