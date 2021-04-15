#include <stdio.h>

int main()
{
  int N[10];

  for(int i=0;i<8;i++)
  {
    scanf("%d",&N[i]);
  }

  int flag_ascending = 0;
  int flag_descending = 0;

  for(int i=0;i<7;i++)
  {
    //printf("TEST [%d] : %d -> %d\n",i,N[i],N[i+1]);
    if(N[i] > N[i+1])
    {
      flag_descending += 1;
    }
    else
    {
      flag_ascending += 1;
    }
  }
  //printf("TT : %d\n", flag_ascending);
  if(flag_ascending == 7)
  {
    printf("ascending");
  }
  else if(flag_descending == 7)
  {
    printf("descending");
  }
  else
  {
    printf("mixed");
  }
  

  return 0;
}