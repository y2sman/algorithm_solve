#include <stdio.h>
#include <string.h>

int main()
{
    char tmp[1000001];
    int counter = 0;

    scanf("%[^\n]s", &tmp);

    for(int i=0;i<strlen(tmp);i++)
    {

        if(i != 0 && i != strlen(tmp) - 1)
        {
            if(tmp[i] == ' ')
            {
                counter++;
            }
        }
    }

    if(strlen(tmp) == 1 && tmp[0] == ' ')
    {
        printf("0");
    }
    else
    {
        printf("%d", counter+1);
    }
    return 0;
}