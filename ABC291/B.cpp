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

int N, tmp, sum;
vector<int> A;

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < 5 * N; i++)
    {
        scanf("%d", &tmp);
        A.emplace_back(tmp);
    }

    sort(all(A));

    for (int i = N; i < 5 * N - N; i++)
    {
        sum += A[i];
    }

    printf("%.15lf", (1.0) * sum / (3 * N));

    return 0;
}