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

int N, M, ans;
vector<vector<int>> A;
vector<int> DP;

void get(int idx, set<int> s)
{
    for (auto i : s)
    {
        bool is_ok = true;
        for (auto j : A[i])
        {
            if (DP[j] == 1)
            {
                is_ok = false;
                break;
            }
        }

        if (!is_ok)
            continue;

        ans++;

        for (auto j : A[i])
        {
            DP[j]--;
        }

        s.erase(i);
        get(idx - 1, s);

        s.insert(i);
        for (auto j : A[i])
        {
            DP[j]++;
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    A.resize(N + 2);
    DP.resize(N + 2, 0);
    for (int i = 1, C; i <= M; i++)
    {
        scanf("%d", &C);
        for (int j = 0, tmp; j < C; j++)
        {
            scanf("%d", &tmp);
            A[i].emplace_back(tmp);
            DP[tmp]++;
        }
    }

    set<int> tmp_s;
    for (int i = 1; i <= N; i++)
    {
        if (DP[i] == 0)
        {
            printf("0");
            return 0;
        }
        tmp_s.insert(i);
    }

    get(N, tmp_s);

    printf("%d", ans);

    return 0;
}