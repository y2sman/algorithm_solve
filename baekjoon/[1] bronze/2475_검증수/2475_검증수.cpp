#include <stdio.h>
#include <math.h>

int main()
{
  int n[10];

  for(int i=0;i<5;i++)
  {
    scanf("%d",&n[i]);
  }

  int sum = 0;
  for(int i=0;i<5;i++)
  {
    sum += pow(n[i],2);
  }

  printf("%d", sum % 10);
  return 0;
}