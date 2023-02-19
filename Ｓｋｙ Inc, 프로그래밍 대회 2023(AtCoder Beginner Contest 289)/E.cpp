/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    printf(__format);
#endif
}

int T;

int solve()
{
    int N, M;
    scanf("%d %d", &N, &M);

    vector<int> C(N + 2, 0);
    vector<vector<int>> graph(N + 2);
    for (int i = 1, tmp; i <= N; i++)
    {
        scanf("%d", &tmp);
        C[i] = tmp;
    }
    for (int i = 0, u, v; i < M; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    vector<vector<bool>> visited(N + 2, vector<bool>(N + 2, false));
    visited[1][N] = true;

    queue<tuple<int, int, int>> q;
    q.emplace(1, 1, N);

    while (!q.empty())
    {
        auto [idx, T_pos, A_pos] = q.front();
        q.pop();

        for (auto T_next_pos : graph[T_pos])
        {
            for (auto A_next_pos : graph[A_pos])
            {
                if (visited[T_next_pos][A_next_pos])
                    continue;

                if (C[T_next_pos] == C[A_next_pos])
                    continue;

                if (T_next_pos == N && A_next_pos == 1)
                    return idx;

                visited[T_next_pos][A_next_pos] = true;
                q.emplace(idx + 1, T_next_pos, A_next_pos);
            }
        }
    }

    return -1;
}

int main()
{
    scanf("%d", &T);

    while (T--)
    {
        printf("%d\n", solve());
    }
    return 0;
}