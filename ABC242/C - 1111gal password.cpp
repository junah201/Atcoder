#include <bits/stdc++.h>
using namespace std;

int N;
long long cnt;
long long pre_DP[10], new_DP[10];

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= 9; i++)
        pre_DP[i] = 1;

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            new_DP[j] = (pre_DP[j - 1] + pre_DP[j] + pre_DP[j + 1]) % 998244353;
        }
        for (int j = 1; j <= 9; j++)
        {
            pre_DP[j] = new_DP[j] % 998244353;
        }
        for (int j = 1; j <= 9; j++)
        {
            if (new_DP[j] < 0)
                printf("===\n");
        }
    }

    for (int j = 1; j <= 9; j++)
    {
        cnt += pre_DP[j];
        cnt %= 998244353;
    }

    printf("\n");

    printf("%lld", cnt);
    return 0;
}