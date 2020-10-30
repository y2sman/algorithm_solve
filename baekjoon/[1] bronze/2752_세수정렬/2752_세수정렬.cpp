#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
       int n[10];
       
       for(int i=0;i<=2;i++)
    {
        scanf("%d",&n[i]);           
       }
   
       sort(n, n+3);
    
    for(int i=0;i<=2;i++)
    {
        printf("%d ",n[i]);          
       }
       
    return 0;
}
