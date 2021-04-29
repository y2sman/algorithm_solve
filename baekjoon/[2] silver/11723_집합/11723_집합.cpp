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

int M;
bool arr[21];

int main()
{
    memset(arr, false, sizeof(arr));
    scanf("%d",&M);

    for(int i=0;i<M;i++)
    {
        char tmp[20];
        int num;
        scanf("%s %d",&tmp, &num);

        if(strcmp(tmp, "add")==0)
        {
            arr[num] = true;
        }
        else if(strcmp(tmp, "remove")==0)
        {
            arr[num] = false;
        }
        else if(strcmp(tmp, "check")==0)
        {
            if(arr[num] == true)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
        else if(strcmp(tmp, "toggle")==0)
        {
            if(arr[num] == true)
            {
                arr[num] = false;
            }
            else
            {
                arr[num] = true;
            }
        }
        else if(strcmp(tmp, "all")==0)
        {
            memset(arr, true, sizeof(arr));
        }
        else if(strcmp(tmp, "empty")==0)
        {
            memset(arr, false, sizeof(arr));
        }
    }

    return 0;
}