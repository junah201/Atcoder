/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
#endif
}

int N, M;

signed main()
{
    scanf("%lld %lld", &N, &M);
    vector<vector<char>> A(N + 2, vector<char>(N + 2, false));
    vector<vector<int>> inp(M + 2, vector<int>(N + 2, false));

    for (int y = 1; y <= M; y++)
    {
        for (int x = 1; x <= N; x++)
        {
            scanf("%lld", &inp[y][x]);
        }
    }

    for (int y = 1; y <= M; y++)
    {
        for (int x = 1; x <= N; x++)
        {
            A[inp[y][x]][inp[y][x]] = true;
            A[inp[y][x]][inp[y][x - 1]] = true;
            A[inp[y][x]][inp[y][x + 1]] = true;
        }
    }

    int ans = 0;

    for (int y = 1; y <= N; y++)
    {
        for (int x = y + 1; x <= N; x++)
        {
            if (A[y][x] == false)
            {
                ans++;
                break;
            }
        }
    }

    printf("%lld", ans);

    return 0;
}