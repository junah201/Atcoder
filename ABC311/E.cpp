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

int get(int size)
{
    int result = 0;
    int cnt = 0;

    for (int y = 1; y <= H - (size - 1); y++)
    {
        cnt = 0;
        for (int x = 1; x <= W - (size - 1); x++)
        {
            if (graph[y][x] == false)
            {
                if (cnt != 0)
                {
                    result += cnt - (size - 1);
                }

                cnt = 0;
            }
            else
            {
                cnt++;
            }
        }
        if (cnt != 0)
        {
            result += cnt - (size - 1);
        }
    }

    return result;
}

signed main()
{
    scanf("%lld %lld %lld", &H, &W, &N);
    graph.resize(H + 1, vector<char>(W + 1, true));

    for (int i = 0; i < N; i++)
    {
        int x, y;
        scanf("%lld %lld", &y, &x);
        graph[y][x] = false;
    }

    int ans = 0;

    for (int size = 1; size <= min(H, W); size++)
    {
        ans += get(size);
    }

    printf("%lld", ans);

    return 0;
}