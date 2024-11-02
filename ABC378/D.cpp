/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int N, M, ans = 0;
vector<int> A, sum;

signed main()
{
    scanf("%lld %lld", &N, &M);
    A.resize(N + 1, 0);
    sum.resize(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &A[i]);
        sum[i] = sum[i - 1] + A[i];
        sum[i] %= M;
    }

    for (int size = 1; size <= N; size++)
    {
        int cur = sum[size - 1];
        // printf("=== %lld %lld ===\n", size, cur);

        for (int i = size; i <= N; i++)
        {
            // printf("size:%lld, i:%lld cur:%lld new_cur:%lld\n", size, i, cur, (cur + A[i]) % M);
            cur += A[i];
            cur -= A[i - size];
            // printf("+%lld\n", A[i]);
            ans += ((cur % M) + M) % M;
            // printf("ans:%lld, ans+=%lld\n", ans, cur % M);
            // printf("-%lld\n", A[i - size]);
            cur %= M;
        }
    }

    printf("%lld\n", ans);

    return 0;
}