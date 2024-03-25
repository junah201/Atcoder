/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
#endif
}

// 스카이라인 쉬운거
int N, ans;
stack<int> s;

signed main()
{
    scanf("%lld", &N);
    vector<int> A(N + 2, 0);

    for (int i = 0, tmp; i < N; i++)
    {
        scanf("%lld %lld", &tmp, &A[i]);
    }
    s.emplace(0);

    for (int i = 0; i < N; i++)
    {
        printf("%lld ", A[i]);
        while (!s.empty() && s.top() > A[i])
            s.pop();

        if (s.empty() || s.top() < A[i])
            ans++;

        s.emplace(A[i]);
    }

    printf("%lld", ans);

    return 0;
}