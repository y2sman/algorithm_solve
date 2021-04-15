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

int N, M;
vector<pair<int, string> > dogam;
vector<pair<int, string> > dogam_str;

void search_num(string str)
{
  int num = stoi(str);
  cout << dogam[num-1].second << "\n";
}

void search_str(string str)
{
  int start = 0;
  int end = dogam_str.size()-1;
  while(1)
  {
    int mid = (start+end)/2;
    int coco = str.compare(dogam_str[mid].second);

    if(coco == 0)
    {
      cout << dogam_str[mid].first << "\n";
      break;
    }

    if(coco > 0)
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }
}

int check_num(string str)
{
  if(isdigit(str[0])!= 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

bool sortbysec(const pair<int, string> &a, const pair<int, string> &b)
{
  return (a.second < b.second);
}

int main()
{
  scanf("%d %d",&N,&M);

  for(int i=1;i<=N;i++)
  {
    char tmp[30];
    scanf("%s",tmp);
    string str = tmp;

    pair<int, string> p = make_pair(i, str);
    dogam.push_back(p);
  }

  dogam_str = dogam;
  sort(dogam_str.begin(), dogam_str.end(), sortbysec);

  for(int i=0;i<M;i++)
  {
    char tmp[30];
    scanf("%s",tmp);
    string str = tmp;

    if(check_num(str) == 1)
    {
      search_num(str);
    }
    else
    {
      search_str(str);
    }
  }

  return 0;
}