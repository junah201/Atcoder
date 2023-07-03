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

int N, M, X;
vector<int> A, visited;
set<int> B;

int main()
{
    scanf("%d", &N);
    for (int i = 0, tmp; i < N; i++)
    {
        scanf("%d", &tmp);
        A.emplace_back(tmp);
    }

    scanf("%d", &M);
    for (int i = 0, tmp; i < M; i++)
    {
        scanf("%d", &tmp);
        B.insert(tmp);
    }

    scanf("%d", &X);
    visited.resize(X + 2, 0);

    queue<int> q;
    q.emplace(0);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        if (now == X)
        {
            printf("Yes");
            return 0;
        }

        for (auto add : A)
        {
            if (now + add > X)
                break;

            if (visited[now + add] == 1)
                continue;

            if (B.find(now + add) == B.end())
            {
                visited[now + add] = 1;
                q.emplace(now + add);
            }
        }
    }

    printf("No");
    return 0;
}