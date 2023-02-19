/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    printf(__format);
#endif
}

int N, M, C_max;
vector<int> B, C;

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 1, tmp; i <= N; i++)
    {
        scanf("%d", &tmp);
        B.emplace_back(tmp);
    }

    for (int i = 1, tmp; i <= M; i++)
    {
        scanf("%d", &tmp);
        C.emplace_back(tmp);
    }

    sort(B.begin(), B.end());

    for (auto i : C)
    {
        int ans = 0;
    }

    return 0;
}