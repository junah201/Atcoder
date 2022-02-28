#include <stdio.h>

int map[9];

int main()
{
    for (int i = 0; i < 10; i++)
        scanf("%d", &map[i]);
    int temp = 0;
    for (int i = 0; i < 3; i++)
    {
        temp = map[temp];
    }
    printf("%d", temp);
    return 0;
}