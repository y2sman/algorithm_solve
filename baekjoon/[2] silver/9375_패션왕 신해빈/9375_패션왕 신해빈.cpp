#include <stdio.h>
#include <string>
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
#include <map>

using namespace std;

int T, n;

void gogo()
{
  map<string, int> m;
  map<string, int>::iterator iter;

  scanf("%d",&n);
  
  for(int i=0;i<n;i++)
  {
    string x, y;
    cin >> x >> y;

    iter = m.find(y);
    if (iter == m.end())
    {
      m[y] = 1;
    }
    else
    {
      m[y] = m[y] + 1;
    }
  }

  int sum = 0;
  int mop = 1;

  if(m.size() == 1)
  {
    for(iter = m.begin(); iter != m.end(); iter++){
      sum += (*iter).second;
    }
    printf("%d\n",sum*mop);
  }
  else
  {
    for(iter = m.begin(); iter != m.end(); iter++){
      mop *= ((*iter).second + 1);
    }
    printf("%d\n",mop-1);
  }
}

int main()
{
  scanf("%d",&T);

  for(int i=0;i<T;i++)
  {
    gogo();
  }

  return 0;
}