/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int N, ans;
vector<int> A;
map<pair<int, int>, int> DP;

int get(int start, int end)
{
    auto pair = make_pair(start, end);
    if (start == end)
        return 0;

    if (start + 1 == end)
    {
        DP.insert(make_pair(pair, ((int)A[start] != A[end])));
    }
    else if (DP.find({start, end}) == DP.end())
    {
        DP.insert(make_pair(pair, ((int)A[start] != A[end]) + get(start + 1, end - 1)));
    }

    return DP[pair];
}

int main()
{
    scanf("%d", &N);
    for (int i = 0, tmp; i < N; i++)
    {
        scanf("%d", &tmp);
        A.emplace_back(tmp);
    }

    for (int i = 0; i < N; i++)
    {
        for (int start = 0, end; start < min(N, N - i); start++)
        {

            end = start + i;
            printf("%d %d\n", start, end);
            ans += get(start, end);
        }
    }

    printf("%d", ans);

    return 0;
}