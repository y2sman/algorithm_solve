#include <stdio.h>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>

using namespace std;

int N, M;
vector <string> hear;
vector <string> output;

bool search_str(string str)
{
    int start = 0;
    int end = hear.size()-1;

    while(1)
    {
        int mid = (start+end)/2;
        int coco = str.compare(hear[mid]);

        if(coco == 0)
        {
            return true;
        }
        if(mid == 0 || mid == hear.size()-1)
        {
            return false;
        }

        if(coco > 0)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
}

int main()
{
    scanf("%d %d",&N,&M);

    for(int i=0;i<N;i++)
    {
        char tmp[30];
        scanf("%s",&tmp);
        hear.push_back(tmp);
    }

    sort(hear.begin(), hear.end());

    for(int i=0;i<M;i++)
    {
        char tmp[30];
        scanf("%s",&tmp);
        /*
        if(search_str(tmp)==true)
        {
            output.push_back(tmp);
        }
        */
       if(binary_search(hear.begin(), hear.end(), tmp) == true)
       {
            output.push_back(tmp);
       }
    }
    sort(output.begin(), output.end());

    printf("%d\n",output.size());
    for(int i=0;i<output.size();i++)
    {
        printf("%s\n",output[i].c_str());
    }

    return 0;
}