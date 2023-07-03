/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int N, M;
vector<vector<int>> graph;

int main()
{
    scanf("%d %d", &N, &M);
    graph.resize(N + 2);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
        printf("%d ", graph[i].size());
        for (auto i : graph[i])
            printf("%d ", i);
        printf("\n");
    }

    return 0;
}