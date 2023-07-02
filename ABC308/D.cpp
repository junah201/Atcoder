/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
#endif
}

int X, Y;
char aim[6] = {'s', 'n', 'u', 'k', 'e'};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

signed main()
{
    scanf("%lld %lld", &Y, &X);
    vector<vector<char>> inp(Y + 1, vector<char>(X + 1));
    vector<vector<char>> visited(Y + 1, vector<char>(X + 1, false));

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            scanf(" %1c", &inp[y][x]);
        }
    }

    if (inp[0][0] != 's')
    {
        printf("No");
        return 0;
    }

    visited[0][0] = true;

    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, 0);

    while (!q.empty())
    {
        auto [x, y, idx] = q.front();
        q.pop();

        if (x == X - 1 && y == Y - 1)
        {
            printf("Yes");
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= X || ny < 0 || ny >= Y)
                continue;

            if (visited[ny][nx])
                continue;

            if (inp[ny][nx] != aim[(idx + 1) % 5])
                continue;

            visited[ny][nx] = true;
            q.emplace(nx, ny, (idx + 1) % 5);
        }
    }

    printf("No");
    return 0;
}