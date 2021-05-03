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

vector<int> map;
vector<pair<int, int> > coord;

int binary_search(int target)
{
  int mid = 0;
  int start = 0;
  int end = coord.size();

  while(1)
  {
    mid = (start + end) / 2;

    if(target == coord[mid].first)
    {
      return coord[mid].second;
    }
    else if(target > coord[mid].first)
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }
}

int main()
{
  scanf("%d",&N);

  for(int i=0;i<N;i++)
  {
    int tmp;
    scanf("%d",&tmp);
    map.push_back(tmp);
    coord.push_back(make_pair(tmp, 0));
  }

  sort(coord.begin(),coord.end());
  coord.erase(unique(coord.begin(),coord.end()),coord.end());

  for(int i=0;i<coord.size();i++)
  {
    coord[i].second = i;
  }
  
  for(int i=0;i<N;i++)
  {
    int tmp = binary_search(map[i]);
    printf("%d ", tmp);
  }

  return 0;
}