/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int N, ans = 0;
vector<vector<int>> graph;

void dfs(int start, int prev, int now)
{
    for (int next : graph[now])
    {
        if (next == prev)
            continue;

        if (graph[next].size() == 3)
        {
            dfs(start, now, next);
        }
        else if (graph[next].size() == 2)
        {
            ans++;
        }
    }
}

signed main()
{
    scanf("%lld", &N);
    graph.resize(N + 1);

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        if (graph[i].size() == 3 || graph[i].size() == 2)
        {
        }
        else
        {
        }
    }

    for (int start = 1; start <= N; start++)
    {
        if (graph[start].size() == 2)
        {
            dfs(start, -1, start);
        }
    }

    printf("%lld\n", ans / 2);
}