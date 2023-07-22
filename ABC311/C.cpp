/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int N;
vector<int> graph;
vector<char> visited;

stack<int> ans;
bool is_cycle = false;
bool end_cycle = false;
int cycle_start = -1;

void dfs(int now, int idx)
{
    visited[now] = idx;

    int next = graph[now];

    if (visited[next] == idx)
    {
        ans.emplace(now);
        is_cycle = true;
        cycle_start = next;
        return;
    }

    if (visited[next] == 0)
    {
        dfs(next, idx);
    }

    if (is_cycle && !end_cycle)
    {
        ans.emplace(now);
        if (now == cycle_start)
        {
            end_cycle = true;
        }
    }
}

signed main()
{
    scanf("%lld", &N);
    graph.resize(N + 1, -1);
    visited.resize(N + 1, false);
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &graph[i]);
    }

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            dfs(i, i);
            if (!ans.empty())
            {
                printf("%lld\n", ans.size());
                while (!ans.empty())
                {
                    printf("%lld ", ans.top());
                    ans.pop();
                }
                return 0;
            }
        }
    }

    return 0;
}