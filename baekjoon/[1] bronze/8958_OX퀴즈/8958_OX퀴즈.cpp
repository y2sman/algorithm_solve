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
  int T = 0;

  scanf("%d", &T);

  for(int i=0;i<T;i++)
  {
    char tmp[100];
    int score = 0;
    int counter = 0;

    scanf("%s",&tmp);

    for(int j=0;j<strlen(tmp);j++)
    {
      if(tmp[j] == 'X')
      {
        score += counter * (counter + 1) / 2;
        counter = 0;
      }
      else if(tmp[j] == 'O')
      {
        counter += 1;
      }
    }

    if(counter != 0)
    {
      score += counter * (counter + 1) / 2;
      counter = 0;
    }
    
    printf("%d\n", score);
    
  }
  return 0;
}