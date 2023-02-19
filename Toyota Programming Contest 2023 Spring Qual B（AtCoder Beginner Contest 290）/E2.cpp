/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int N, start_idx, end_idx, A[200002];
ll ans, cnt;

int main()
{
    scanf("%d", &N);
    for (int i = 0, tmp; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < N; i++)
    {
        start_idx = i - 1, end_idx = i + 1;
        cnt = 0;
        while (start_idx >= 0 && end_idx < N)
        {
            cnt += A[start_idx] != A[end_idx];
            ans += cnt;

            start_idx--;
            end_idx++;
        }
    }

    for (int i = 0; i < N - 1; i++)
    {
        start_idx = i, end_idx = i + 1;
        cnt = 0;
        while (start_idx >= 0 && end_idx < N)
        {
            cnt += A[start_idx] != A[end_idx];
            ans += cnt;

            start_idx--;
            end_idx++;
        }
    }

    printf("%lld", ans);

    return 0;
}