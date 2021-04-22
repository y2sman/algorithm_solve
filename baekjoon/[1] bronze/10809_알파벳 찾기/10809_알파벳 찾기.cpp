#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    char tmp[101];
    vector<int> num[30];

    scanf("%s",&tmp);

    for(int i=0;i<strlen(tmp);i++)
    {
        num[tmp[i]-96].push_back(i);
    }

    for(int i=1;i<=26;i++)
    {
        if(num[i].size() == 0)
        {
            printf("-1 ");
        }
        else
        {
            printf("%d ", num[i].front());
        }
    }

    return 0;
}