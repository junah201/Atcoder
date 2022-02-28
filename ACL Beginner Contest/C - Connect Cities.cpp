#include <bits/stdc++.h>
using namespace std;

int N, M, cnt;
vector<vector<int>> graph;
vector<int> visited;

void dfs(int idx)
{
    visited[idx] = 1;
    for (auto i : graph[idx])
        if (!visited[i])
            dfs(i);
}

int main()
{
    scanf("%d %d", &N, &M);
    graph.resize(N + 1);
    visited.resize(N + 1, 0);
    for (int i = 0, a, b; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            cnt++;
        }
    }
    printf("%d", cnt - 1);
    return 0;
}