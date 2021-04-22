#include <stdio.h>

int main()
{
    int N, M = 0;
    int score[1001];

    scanf("%d",&N);

    for(int i=0;i<N;i++)
    {
        scanf("%d",&score[i]);

        if( M < score[i] )
        {
            M = score[i];
        }
    }

    float sum = 0;
    for(int i=0;i<N;i++)
    {
        sum += ( (double)score[i] / (double)M ) * 100;
    }

    printf("%f",sum / (double)N );
    return 0;
}