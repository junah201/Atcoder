/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int N, K, max_day = -1;

signed main()
{
    scanf("%lld %lld", &N, &K);
    vector<pair<int, int>> pills;

    for (int i = 0; i < N; i++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        pills.emplace_back(a, b);
        max_day = max(max_day, a);
    }

    sort(all(pills));

    vector<pair<int, int>> new_pills;
    new_pills.emplace_back(pills[0]);

    for (int i = 1; i < pills.size(); i++)
    {
        if (pills[i - 1].first != pills[i].first)
        {
            new_pills.emplace_back(pills[i]);
        }
        else
        {
            new_pills.back() = {
                new_pills.back().first,
                new_pills.back().second + pills[i].second};
        }
    }
    new_pills.emplace_back(0LL, 0LL);

    int ans = max_day + 1;
    for (int i = new_pills.size() - 2; i >= 0; i--)
    {
        new_pills[i].second += new_pills[i + 1].second;
        if (new_pills[i].second <= K)
        {
            if (i != 0)
                ans = new_pills[i - 1].first + 1;
            else
            {
                ans = 1;
            }
        }
    }

    printf("%lld", ans);

    return 0;
}
