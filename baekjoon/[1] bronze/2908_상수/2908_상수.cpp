#include <stdio.h>

int main()
{
    char A[4], B[4];

    scanf("%s %s", &A, &B);

    for(int i=2;i>=0;i--)
    {
        if(A[i] > B[i])
        {
            printf("%c%c%c",A[2],A[1],A[0]);
            break;
        }
        else if(A[i] < B[i])
        {
            printf("%c%c%c",B[2],B[1],B[0]);
            break;
        }
    }
    return 0;
}