/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int N, ans = 0;
int bits[3];

signed main()
{
    for (int i = 0; i < 3; i++)
    {
        bits[i] = (int)(1 << i);
    }

    scanf("%lld", &N);
    vector<int> A(N);
    vector<char> S(N);
    for (int i = 0; i < N; i++)
        scanf("%lld", &A[i]);

    for (int i = 0; i < N; i++)
        scanf(" %1c", &S[i]);

    vector<int> M(3, 0);
    vector<int> E(20);

    for (int i = 0; i < N; i++)
    {
        if (S[i] == 'M')
        {
            M[A[i]] += 1;
        }
        else if (S[i] == 'E')
        {
            for (int j = 0; j <= 2; j++)
            {
                E[bits[A[i]] | bits[j]] += M[j];
            }
        }
        else if (S[i] == 'X')
        {
            for (int k = 0; k <= 7; k++)
            {
                if (E[k] == 0)
                    continue;

                int tmp = (bits[A[i]] | k);
                if (tmp == 1 || tmp == 5)
                {
                    ans += 1 * E[k];
                }
                else if (tmp == 3)
                {
                    ans += 2 * E[k];
                }
                else if (tmp == 7)
                {
                    ans += 3 * E[k];
                }
            }
        }
    }

    printf("%lld", ans);

    return 0;
}
