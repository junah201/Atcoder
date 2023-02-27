/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int N;
ll DP[200002][2];

int main()
{
    scanf("%d", &N);

    int pre_A, pre_B, A, B;
    scanf("%d %d", &pre_A, &pre_B);
    DP[0][0] = 1;
    DP[0][1] = 1;

    for (int i = 1; i < N; i++)
    {
        scanf("%d %d", &A, &B);
        if (pre_A == A && pre_B == B)
        {
            DP[i][1] = DP[i - 1][0];
            DP[i][0] = DP[i - 1][1];
        }
        else if (pre_A == B && pre_B == A)
        {
            DP[i][1] = DP[i - 1][1];
            DP[i][0] = DP[i - 1][0];
        }
        else if (pre_A == B)
        {
            DP[i][1] = DP[i - 1][1];
            DP[i][0] = DP[i - 1][0] + DP[i - 1][1];
        }
        else if (pre_B == B)
        {
            DP[i][1] = DP[i - 1][0];
            DP[i][0] = DP[i - 1][1] + DP[i - 1][0];
        }
        else
        {
            DP[i][0] = DP[i - 1][0] + DP[i - 1][1];
            DP[i][1] = DP[i - 1][0] + DP[i - 1][1];
        }
        DP[i][0] %= 998244353;
        DP[i][1] %= 998244353;
        pre_A = A;
        pre_B = B;
    }

    printf("%lld", (DP[N - 1][0] + DP[N - 1][1]) % 998244353);

    return 0;
}