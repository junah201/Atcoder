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

int N, K, ans;
vector<int> A, DP;

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0, tmp; i < N; i++)
    {
        scanf("%d", &tmp);
        A.emplace_back(tmp);
    }

    DP.resize(K + 2, 0);

    for (int i = 0; i < N; i++)
    {
        if (A[i] >= K)
            continue;
        DP[A[i]] = true;
    }

    for (int j = 0; j < K; j++)
    {
        if (DP[j])
            ans++;
        else
            break;
    }

    printf("%d", ans);

    return 0;
}