/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int N;
ll ans;
vector<int> A;
map<pair<int, int>> DP;

int main()
{
    scanf("%d", &N);
    for (int i = 0, tmp; i < N; i++)
    {
        scanf("%d", &tmp);
        A.emplace_back(tmp);
    }

    for (int y = 0; y < N; y++)
    {
        for (int x = y + 1; x < N; x++)
        {
            DP.insert(make_pair(make_pair(y, x), (int)(A[y] != A[x])));
        }
    }

    for (int i = 0; i < N; i++)
    {
        int start = i, end = i + 1;
    }

    printf("%lld", ans);

    return 0;
}