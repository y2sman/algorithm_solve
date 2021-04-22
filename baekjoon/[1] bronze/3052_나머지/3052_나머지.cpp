#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int counter = 0;
    vector<int> num[43];

    for(int i=0;i<10;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        num[tmp%42].push_back(tmp%42);
    }

    for(int i=0;i<42;i++)
    {
        if(num[i].size() != 0)
        {
            counter++;
        }
    }

    printf("%d",counter);

    return 0;
}