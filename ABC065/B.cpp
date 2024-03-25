/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int N;
vector<char> visited;

signed main()
{
    scanf("%lld", &N);
    visited.resize(N + 1, false);
    vector<int> A(N + 1);

    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &A[i]);
    }

    int now = 1;
    int cnt = 0;

    while (true)
    {
        if (visited[now])
        {
            printf("-1");
            return 0;
        }
        if (now == 2)
            break;

        visited[now] = true;
        now = A[now];
        cnt++;
    }

    printf("%d", cnt);
    return 0;
}