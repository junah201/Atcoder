/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int N;
int inp[6561][6561];

void get(int idx, int x, int y)
{
    if (idx == 3)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                inp[y + i][x + j] = 1;
        inp[y + 1][x + 1] = 0;
        return;
    }
    int temp = idx / 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
                continue;
            get(temp, x + i * temp, y + j * temp);
        }
    }
}

signed main()
{
    scanf("%d", &N);

    if (N == 0)
    {
        printf("#");
        return 0;
    }

    N = pow(3, N);
    get(N, 0, 0);
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (inp[y][x] == 0)
                printf(".");
            else
                printf("#");
        }
        printf("\n");
    }
    return 0;
}