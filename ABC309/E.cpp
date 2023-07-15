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

int N, M;
vector<int> p;
vector<int> is_cover;
vector<vector<int>> graph;

void dfs(int now, int cover)
{
    cover = max(cover, is_cover[now]);
    is_cover[now] = cover;

    // printf("now:%lld cover:%lld\n", now, cover);

    for (int next : graph[now])
    {
        if (cover == 0)
            dfs(next, 0);
        else
            dfs(next, cover - 1);
    }
}

signed main()
{
    scanf("%lld %lld", &N, &M);
    p.resize(N + 1, 0);
    is_cover.resize(N + 1, 0);
    graph.resize(N + 1);
    for (int i = 2; i <= N; i++)
    {
        scanf("%lld", &p[i]);
        graph[p[i]].emplace_back(i);
    }
    for (int i = 0; i < M; i++)
    {
        int x, y;
        scanf("%lld %lld", &x, &y);
        is_cover[x] = max(is_cover[x], y + 1);
    }

    dfs(1, 0);

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        // printf("%lld: %lld\n", i, is_cover[i]);
        if (is_cover[i])
            ans++;
    }

    printf("%lld", ans);

    return 0;
}