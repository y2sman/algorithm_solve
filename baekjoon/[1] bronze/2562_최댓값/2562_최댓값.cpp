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
  vector<int> num;
  
  for(int i=0;i<9;i++)
  {
    int tmp;
    scanf("%d", &tmp);
    num.push_back(tmp);
  }

  int max = *max_element(num.begin(), num.end());
  printf("%d\n", max);

  vector<int>::iterator p = find(num.begin(),num.end(),max);
  printf("%ld", distance(num.begin(),p)+1);

  return 0;
}