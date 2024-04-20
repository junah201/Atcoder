/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int N, M, ans = 0, node, edge;
vector<vector<int>> graph;
vector<int> visited;

void dfs(int idx)
{
    visited[idx] = true;
    edge += 1;
    node += graph[idx].size();

    for (auto next : graph[idx])
    {
        if (visited[next])
            continue;

        dfs(next);
    }
}

signed main()
{
    scanf("%lld %lld", &N, &M);
    graph.resize(N + 1);
    visited.resize(N + 1);

    for (int i = 0, a, b; i < M; i++)
    {
        scanf("%lld %lld", &a, &b);
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        if (visited[i])
            continue;

        node = 0;
        edge = 0;
        dfs(i);

        int total = (edge * (edge - 1)) / 2;

        ans += total - (node / 2);
    }

    printf("%lld", ans);
    return 0;
}