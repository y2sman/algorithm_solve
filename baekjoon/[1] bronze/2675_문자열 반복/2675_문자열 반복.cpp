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
    int R;
    char S[100];

    scanf("%d",&R);
    scanf("%s", S);
    
    for(int i=0;i<strlen(S);i++)
    {
      for(int j=0;j<R;j++)
      {
        printf("%c",S[i]);
      }
    }
    printf("\n");
  }

  return 0;
}