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

int N;

signed main()
{
    scanf("%lld", &N);
    vector<pair<long double, int>> v;
    for (int i = 1; i <= N; i++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);

        long double da = (long double)a, db = (long double)b;

        v.emplace_back(da / (da + db), -i);
    }
    sort(v.begin(), v.end());

    for (int i = v.size() - 1; i >= 0; i--)
    {
        printf("%lld ", -v[i].second);
    }

    return 0;
}