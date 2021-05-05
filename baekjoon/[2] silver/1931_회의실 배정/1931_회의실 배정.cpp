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
int counter;

vector<pair<unsigned int, unsigned int> > table;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
  if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main()
{ 
  scanf("%d",&N);

  for(int i=0;i<N;i++)
  {
    int x, y;
    scanf("%d %d",&x,&y);
    table.push_back(make_pair(x,y));
  }

  sort(table.begin(), table.end(), compare);

  int end_time = 0;

  for(int i=0;i<N;i++)
  {
    if( end_time <= table[i].first )
    {
      end_time = table[i].second;
      counter++;
    }
  }

  printf("%d",counter);

  return 0;
}