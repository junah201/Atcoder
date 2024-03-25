/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int X, Y;
int ans;
vector<vector<int>> inp;

int dx[8] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, 1, -1, -1, 1, 1, -1};

void dfs(int x, int y)
{
    inp[y][x] = 0;

    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= X || ny < 0 || ny >= Y)
            continue;

        if (inp[ny][nx] == 0)
            continue;

        dfs(nx, ny);
    }
}

signed main()
{
    scanf("%lld %lld", &Y, &X);
    inp.resize(Y, vector<int>(X));
    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            char t;
            scanf(" %1c", &t);
            if (t == '.')
                inp[y][x] = 0;
            else
                inp[y][x] = 1;
        }
    }

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            if (inp[y][x])
            {
                dfs(x, y);
                ans++;
            }
        }
    }

    printf("%lld", ans);

    return 0;
}