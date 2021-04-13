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
  int N;
  vector<int> num;

  scanf("%d",&N);
  
  for(int i=0;i<N;i++)
  {
    int tmp;
    scanf("%d", &tmp);
    num.push_back(tmp);
  }

  printf("%d %d", *min_element(num.begin(), num.end()), *max_element(num.begin(), num.end()) );

  return 0;
}