/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int N, M, ans = -1;
vector<int> A;

int search(int start, int end)
{
    if (start > end)
        return end;
    int mid = (start + end) / 2;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        cnt += min(mid, A[i]);
    }
    if (cnt > M)
        return search(start, mid - 1);
    ans = max(ans, mid);
    return search(mid + 1, end);
}

signed main()
{
    scanf("%lld %lld", &N, &M);
    A.resize(N);
    int tmp_sum = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
        tmp_sum += A[i];
    }

    if (tmp_sum <= M)
    {
        printf("infinite");
        return 0;
    }
    search(1, INT_MAX);
    printf("%lld", ans);

    return 0;
}