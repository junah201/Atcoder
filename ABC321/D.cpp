/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int N, M, P;
int ans;

signed main()
{
    scanf("%lld %lld %lld", &N, &M, &P);
    vector<int> A(N), B(M), sum(M + 1);

    for (int i = 0; i < N; i++)
        scanf("%lld", &A[i]);

    for (int i = 0; i < M; i++)
        scanf("%lld", &B[i]);

    sort(all(A));
    sort(all(B));

    sum[0] = 0;
    for (int i = 0; i < M; i++)
        sum[i + 1] = sum[i] + B[i];

    for (auto i : A)
    {
        int idx = lower_bound(all(B), P - i) - B.begin();

        ans += (idx * i) + sum[idx];
        ans += (M - idx) * P;
    }

    printf("%lld", ans);

    return 0;
}