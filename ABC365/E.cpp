/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int N, total = 0;
vector<int> V, P;

int get(int k)
{
    int ret = 0;
    for (int i = 1; i <= N; i++)
        P[i] = P[i - 1] + (V[i] >> k & 1);
    for (int i = 0; i < N; i++)
    {
        if (V[i] >> k & 1)
            ret += (N - i) - (P[N] - P[i]);
        else
            ret += P[N] - P[i];
    }
    return ret;
}

signed main()
{
    scanf("%lld", &N);
    V.resize(N + 1, 0);
    V.resize(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &V[i]);
        total += V[i];
        V[i] ^= V[i - 1];
    }

    int res = 0;
    for (int i = 0; i < 30; i++)
    {
        res += get(i) << i;
    }

    printf("%lld", res - total);

    return 0;
}