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

int H, W, N;
vector<vector<char>> graph;
vector<vector<vector<int>>> dp;

void get2(int x, int y, int size)
{
    if (!dp[y][x][size - 1])
        return;

    for (int ny = y; ny < y + size; ny++)
        if (graph[ny][x] == false)
            return;

    for (int nx = x; nx < x + size; nx++)
        if (graph[y][nx] == false)
            return;

    dp[y][x][size] = 1;
}

void get(int size)
{
    for (int y = 1; y <= H - (size - 1); y++)
    {
        for (int x = 1; x <= W - (size - 1); x++)
        {
            get2(x, y, size);
        }
    }
}

signed main()
{
    scanf("%lld %lld %lld", &H, &W, &N);
    graph.resize(H + 1, vector<char>(W + 1, true));
    dp.resize(H + 1, vector<vector<int>>(W + 1, vector<int>(3000, 0)));

    for (int i = 0; i < N; i++)
    {
        int x, y;
        scanf("%lld %lld", &y, &x);
        graph[y][x] = false;
    }

    // dp init
    for (int y = 1; y <= H; y++)
    {
        for (int x = 1; x <= W; x++)
        {
            if (graph[y][x])
                dp[y][x][1] = 1;
        }
    }

    int ans = 0;

    for (int size = 2; size <= min(H, W); size++)
    {
        get(size);
    }

    for (int y = 1; y <= H; y++)
    {
        for (int x = 1; x <= W; x++)
        {
            for (int size = 1; size <= min(H, W); size++)
            {
                if (dp[y][x][size])
                {
                    printf("(%lld %lld) size:%lld\n", x, y, size);
                    ans++;
                }
            }
        }
    }

    for (int size = 1; size <= min(H, W); size++)
    {
        for (int y = 1; y < H - (size - 1); y++)
        {
            for (int x = 1; x < W - (size - 1); x++)
            {
                if (dp[y][x][size])
                {
                    printf("(%lld %lld) size:%lld\n", x, y, size);
                    ans++;
                }
            }
        }
    }

    printf("%lld", ans);

    return 0;
}