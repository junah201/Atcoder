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

int N1, N2, M;
vector<vector<int>> graph;
vector<int> dis;

void bfs(int start_node)
{
    queue<pair<int, int>> q;
    q.emplace(start_node, 0);
    dis[start_node] = 0;

    while (!q.empty())
    {
        auto [now, cost] = q.front();
        q.pop();

        for (auto next : graph[now])
        {
            if (dis[next] != -1)
                continue;

            dis[next] = cost + 1;
            q.emplace(next, cost + 1);
        }
    }
}

signed main()
{
    scanf("%lld %lld %lld", &N1, &N2, &M);
    graph.resize(N1 + N2 + 1);
    dis.resize(N1 + N2 + 1, -1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    bfs(1);
    bfs(N1 + N2);

    int max1 = 0;
    int max2 = 0;

    for (int s = 1; s <= N1; s++)
    {
        max1 = max(max1, dis[s]);
    }

    for (int e = N1 + 1; e <= N1 + N2; e++)
    {
        max2 = max(max2, dis[e]);
    }

    printf("%lld", max1 + max2 + 1);

    return 0;
}