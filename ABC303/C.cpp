/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
#endif
}

int N, M, H, K;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<char> S;
set<pair<int, int>> item;

int get(char tmp)
{
    if (tmp == 'R')
        return 0;
    if (tmp == 'L')
        return 1;
    if (tmp == 'U')
        return 2;
    if (tmp == 'D')
        return 3;
    return -1;
}

signed main()
{
    scanf("%lld %lld %lld %lld", &N, &M, &H, &K);
    S.resize(N + 2);
    for (int i = 0; i < N; i++)
    {
        scanf(" %c", &S[i]);
    }

    for (int i = 0, x, y; i < M; i++)
    {
        scanf("%lld %lld", &x, &y);
        item.emplace(x, y);
    }

    int x = 0, y = 0;
    for (int i = 0; i < N; i++)
    {
        x += dx[get(S[i])];
        y += dy[get(S[i])];
        H--;

        if (H < 0)
        {
            printf("No");
            return 0;
        }

        // printf("%lld : (%lld %lld), %lld\n", i, x, y, H);
        if (item.find(make_pair(x, y)) != item.end() && H < K)
        {
            // dprintf("use\n");
            H = K;
            item.erase(make_pair(x, y));
        }
    }

    printf("Yes");
    return 0;
}