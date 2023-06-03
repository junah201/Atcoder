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

int N, M, K, Q;
vector<vector<int>> graph;
vector<int> id;
vector<pair<int, int>> is_not_allow;

void bfs(int s, int idx)
{
    queue<int> q;
    q.emplace(s);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        id[now] = idx;

        for (auto next : graph[now])
        {
            if (id[next])
                continue;

            id[next] = idx;
            q.emplace(next);
        }
    }
}

signed main()
{
    scanf("%lld %lld", &N, &M);
    graph.resize(N + 1);
    id.resize(N + 1, false);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        scanf("%lld %lld", &u, &v);
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    for (int i = 1, now_id = 1; i <= N; i++)
    {
        if (!id[i])
        {
            bfs(i, now_id);
            now_id++;
        }
    }

    scanf("%lld", &K);
    set<pair<int, int>> s;

    for (int i = 0; i < K; i++)
    {
        int x, y;
        scanf("%lld %lld", &x, &y);
        s.emplace(min(id[x], id[y]), max(id[x], id[y]));
        // scanf("%lld %lld", &is_not_allow[i].first, &is_not_allow[i].second);
    }

    scanf("%lld", &Q);

    while (Q--)
    {
        int p, q;
        scanf("%lld %lld", &p, &q);

        bool ans = true;

        if (id[p] == id[q])
        {
            printf("Yes\n");
            continue;
        }

        if (s.find({min(id[p], id[q]), max(id[p], id[q])}) == s.end())
        {
            printf("Yes\n");
        }
        else
            printf("No\n");
    }

    return 0;
}