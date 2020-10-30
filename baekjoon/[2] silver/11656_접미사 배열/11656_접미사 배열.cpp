#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

char S[1001];
int size;
char tmp[1001][1001];

vector<string> tmp2;

int main()
{    
    scanf("%s",&S);
     
    size = strlen(S);
    
    for(int i=0;i<=strlen(S);i++)
    {
        strcpy(tmp[i],S+i);
        tmp2.push_back(tmp[i]);
    }
        
    sort(tmp2.begin(),tmp2.end());
    
    for(int i=1;i<=size;i++)
    {
        printf("%s\n", tmp2[i].c_str());
    }
       
    return 0;
}