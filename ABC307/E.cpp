/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF LONG_LONG_MAX
#define MOD 998244353

int N, M;

signed main()
{
    scanf("%lld %lld", &N, &M);

    vector<int> DP(N + 1, 0);

    DP[0] = M;

    for (int i = 1; i < N; i++)
    {
        DP[i] = M * (DP[i - 1] - (DP[i - 1] / M));
        DP[i] %= MOD;
    }

    if (M == 2)
    {
        printf("%lld", DP[N - 1]);
        return 0;
    }

    vector<int> DP2(N, 0);
    int K = M - 1;
    DP2[0] = K;

    for (int i = 1; i < N - 2; i++)
    {
        DP2[i] = K * ((DP2[i - 1] - (DP2[i - 1] / K)));
        DP2[i] %= MOD;
    }

    // M *(M - 1개의 색깔을 가지고 N - 2 칸을 채우는 방법)

    // int ans = 0;
    // for (int i = 0; i < M; i++)
    // {
    //     ans += DP[N - 1][i];
    // }

    // printf("%lld", ans);

    // printf("\n===\n");
    printf("\n%lld", (DP[N - 1] - DP2[N - 3] * M) % MOD);

    return 0;
}

/*
N개의 칸을 M개의 색깔로 서로 인접하지 않게 채우는 방법
에서

N-2개의 칸을 M-1개의 색깔로 서로 인접하지 않게 채우는 방법
을 M번 곲한 값을 빼면 정답 아닌가?
*/
