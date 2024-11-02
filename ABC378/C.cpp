/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
#endif
}

int X, Y, K;
vector<vector<int>> inp;
vector<vector<int>> visited;

int ans = 0;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int dep)
{
    // dprintf("(%lld, %lld) : %lld\n", x, y, dep);
    if (dep == K)
    {
        ans++;
        // printf("ans++\n");
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int rx = x + dx[i];
        int ry = y + dy[i];

        if (rx < 0 || rx >= X || ry < 0 || ry >= Y)
            continue;

        if (inp[ry][rx] == 0)
            continue;

        if (visited[ry][rx])
            continue;

        visited[ry][rx] = 1;
        dfs(rx, ry, dep + 1);
        visited[ry][rx] = 0;
    }
}

signed main()
{
    scanf("%lld %lld %lld", &Y, &X, &K);
    inp.resize(Y, vector<int>(X, 0));
    visited.resize(Y, vector<int>(X, 0));

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            char tmp;
            scanf(" %1c", &tmp);

            if (tmp == '.')
            {
                inp[y][x] = 1;
            }
            else
            {
                inp[y][x] = 0;
            }
        }
    }

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            if (inp[y][x])
            {
                // dprintf("== %lld %lld ==\n", x, y);
                visited[y][x] = 1;
                dfs(x, y, 0);
                visited[y][x] = 0;
            }
        }
    }

    printf("%lld", ans);

    return 0;
}