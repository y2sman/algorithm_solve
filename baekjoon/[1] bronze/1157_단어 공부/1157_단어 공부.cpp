#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    char tmp[1000001];
    vector<int> num[30];

    scanf("%s", &tmp);

    int leng = strlen(tmp);
    for(int i=0;i<leng;i++)
    {
        if( 65 <= tmp[i] && tmp[i] <= 90)
        {
            int iter = tmp[i]-65;
            num[iter].push_back(iter);
        }
        else if( 97 <= tmp[i] && tmp[i] <= 122 )
        {
            int iter = tmp[i]-97;
            num[iter].push_back(iter);
        }
    }

    int max = 1;
    int counter = 1;

    for(int i=0;i<26;i++)
    {
        int size = num[i].size();

        if(size != 0)
        {
            int cmp_size = num[max].size();

            if(cmp_size < size)
            {
                max = i;
                counter = 1;
            }
            else if(cmp_size == size)
            {
                counter += 1;
            }
        }
    }

    if(counter == 1)
    {
        printf("%c",max+65);
    }
    else
    {
        printf("?");
    }

    return 0;
}