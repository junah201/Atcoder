/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX
#define MOD 998244353

int modPow(int base, int exp)
{
    int result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int modDivide(int a, int b)
{
    int inverse = modPow(b, MOD - 2);
    return (a * inverse) % MOD;
}

signed main()
{
    int N, X, max_key = 0;
    scanf("%lld %lld", &N, &X);
    vector<int> T(N);
    for (int i = 0; i < N; i++)
        scanf("%lld", &T[i]);

    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, 0);
    map<int, int> myMap;

    while (!q.empty())
    {
        auto [now, time, cnt] = q.front();
        q.pop();

        if (time > X)
        {
            if (now == 0)
            {
                myMap[cnt] += 1;
                max_key = max(max_key, cnt);
            }
            continue;
        }

        for (int i = 0; i < N; i++)
        {
            q.emplace(i, time + T[i], cnt + 1);
        }
    }

    for (int i = 0; i < max_key; i++)
    {
        myMap[i + 1] += myMap[i] * N;
    }

    // int up = myMap[max_key];
    // int down = 1;
    // for (int i = 0; i < max_key; i++)
    // {
    //     down *= N;
    // }

    // for (int div = 2;; div++)
    // {
    //     while (up % div == 0 && down % div == 0)
    //     {
    //         up %= div;
    //         down %= div;
    //     }

    //     if (div * div > min(up, down))
    //         break;
    // }

    // // printf("up: %lld, down:%lld\n", up, down);

    // int ans = modDivide(up, down);
    // printf("%lld", ans);

    return 0;
}