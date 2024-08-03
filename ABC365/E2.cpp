#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

using u64 = unsigned long long;

int n, v[200'001], P[200'001], total = 0;

u64 Sol(int k)
{
    u64 ret = 0;
    for (int i = 1; i <= n; i++)
        P[i] = P[i - 1] + (v[i] >> k & 1);
    for (int i = 0; i < n; i++)
    {
        if (v[i] >> k & 1)
            ret += (n - i) - (P[n] - P[i]);
        else
            ret += P[n] - P[i];
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        total += tmp;
        v[i] = tmp ^ v[i - 1];
    }
    u64 res = 0;
    for (int i = 0; i < 30; i++)
        res += Sol(i) << i;

    cout << res - total << '\n';
}