/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    printf(__format);
#endif
}

int N;
char inp[12];

int main()
{
    scanf("%s", inp);

    int len = strlen(inp);
    for (int i = 0; i < len; i++)
    {
        if (inp[i] == '1')
            printf("0");
        else
            printf("1");
    }

    return 0;
}