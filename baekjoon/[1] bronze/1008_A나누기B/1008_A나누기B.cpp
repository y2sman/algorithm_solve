#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
  long double	A, B;
  scanf("%Lf %Lf",&A,&B);

  printf("%.10Lf",A/B);
  return 0;
}