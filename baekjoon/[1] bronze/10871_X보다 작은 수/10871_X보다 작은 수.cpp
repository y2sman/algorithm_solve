#include <stdio.h>

int main()
{
    int N, X;
    int num[10001];

    scanf("%d %d",&N,&X);

    for(int i=0;i<N;i++)
    {
        scanf("%d",&num[i]);
    }

    for(int i=0;i<N;i++)
    {  
        if(num[i] < X)
        {
            printf("%d ",num[i]);
        }
    }

    return 0;
}