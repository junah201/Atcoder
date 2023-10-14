/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

signed main()
{
    int ans = 0;
    int N;
    scanf("%lld", &N);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < N; i++)
    {
        int s, c;
        scanf("%lld %lld", &s, &c);

        pq.emplace(s, c);
    }

    while (!pq.empty())
    {
        auto [s, c] = pq.top();
        pq.pop();

        while (!pq.empty())
        {
            auto [ns, nc] = pq.top();
            if (s != ns)
                break;
            pq.pop();
            c += nc;
        }

        ans += c % 2;
        if (c > 1)
        {
            pq.emplace(s * 2, c / 2);
        }
    }

    printf("%lld", ans);

    return 0;
}