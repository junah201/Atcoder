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

int N, cnt = 0;

signed main()
{
    scanf("%lld", &N);

    if (N == 0)
    {
        printf("0\n");
        return 0;
    }
    if (N > 1022)
    {
        printf("-1");
        return 0;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= 9; i++)
        pq.emplace(i);

    while (!pq.empty())
    {
        int top = pq.top();
        pq.pop();

        cnt++;

        if (cnt == N)
        {
            printf("%lld\n", top);
            return 0;
        }

        for (int i = 0; i < top % 10; i++)
        {
            pq.emplace(top * 10 + i);
        }
    }

    return 0;
}