#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>

using namespace std;

int N;
int alphabet[26];
char alpha[20][20];

int main()
{
    memset(alpha, '0' ,sizeof(alpha));

    scanf("%d",&N);

    for(int i=0;i<N;i++)
    {
        scanf("%s",&alpha[i]);
        int size = strlen(alpha[i]);

        for(int j=size-1;j>=0;j--)
        {
            int tmp = alpha[i][j]-65;
            alphabet[tmp] += pow(10,size-j-1);
        }
    }

    sort(alphabet,alphabet+26, greater<int>());
    
    int tmp = 0;
    for(int i=0;i<10;i++)
    {
        tmp += alphabet[i] * (9-i);
    }

    printf("%d",tmp);
    return 0;
}
