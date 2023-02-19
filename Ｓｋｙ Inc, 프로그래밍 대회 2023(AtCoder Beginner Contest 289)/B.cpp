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

int N, M;
vector<int> A;
stack<int> S;

int main()
{
    scanf("%d %d", &N, &M);
    A.resize(N + 2, 0);

    for (int i = 0, tmp; i < M; i++)
    {
        scanf("%d", &tmp);
        A[tmp] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        S.emplace(i);
        if (A[i] == 0)
        {
            while (!S.empty())
            {
                printf("%d ", S.top());
                S.pop();
            }
        }
    }

    return 0;
}