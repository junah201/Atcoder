/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int X, Y, N;
vector<vector<int>> inp, visited, DP;
vector<tuple<int, int, int>> xye;
vector<vector<bool>> is_reach_able;
int start_x, start_y;
int end_x, end_y;
constexpr array<pair<int, int>, 4> dxy = {{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}};

vector<vector<int>> bfs(const int sx, const int sy, const int se)
{
    vector<vector<int>> dist(Y, vector<int>(X, INF));
    dist[sx][sy] = 0;

    if (inp[sy][sx] == '#')
        return dist;

    queue<tuple<int, int, int>> q;
    q.emplace(sx, sy, se);

    while (!q.empty())
    {
        const auto [x, y, e] = q.front();
        q.pop();

        if (e == 0)
            continue;

        for (const auto &[dx, dy] : dxy)
        {
            const int rx = x + dx, ry = y + dy;
            if (rx < 0 || ry < 0 || rx >= X || ry >= Y)
                continue;

            if (inp[ry][rx] == '#')
                continue;

            if (dist[ry][rx] <= dist[y][x] + 1)
                continue;

            dist[ry][rx] = dist[y][x] + 1;
            q.emplace(rx, ry, e - 1);
        }
    }

    return dist;
}

vector<bool> bfs2(const int s)
{
    queue<int> q;
    vector<bool> is_seen(N);
    q.emplace(s);

    while (!q.empty())
    {
        const int idx = q.front();
        q.pop();
        for (int t = 0; t < N; ++t)
        {
            if (is_reach_able[idx][t] and (not is_seen[t]))
            {
                is_seen[t] = true;
                q.push(t);
            }
        }
    }

    return is_seen;
}

signed main()
{
    scanf("%lld %lld", &Y, &X);
    inp.resize(Y, vector<int>(X, -1));
    visited.resize(Y, vector<int>(X, 0));
    DP.resize(Y, vector<int>(X, 0));

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            char a;
            scanf(" %1c", &a);
            if (a == '.')
            {
                inp[y][x] = 0;
            }
            else if (a == '#')
            {
                inp[y][x] = -1;
            }
            else if (a == 'S')
            {
                inp[y][x] = 0;
                start_x = x;
                start_y = y;
            }
            else if (a == 'T')
            {
                inp[y][x] = 0;
                end_x = x;
                end_y = y;
            }
        }
    }

    scanf("%lld", &N);
    xye.resize(N);
    for (int i = 0; i < N; i++)
    {
        int tx, ty, te;
        scanf("%lld %lld %lld", &ty, &tx, &te);
        xye[i] = {tx - 1, ty - 1, te};
        inp[ty - 1][tx - 1] = te;
    }
    xye.emplace_back(start_x, start_y, 0);
    xye.emplace_back(end_x, end_y, 0);

    is_reach_able.resize(N, vector<bool>(N));

    vector<vector<int>> dist;

    if (inp[start_y][start_x] == 0)
    {
        printf("No");
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        auto [sx, sy, se] = xye[i];
        auto distMap = bfs(sx, sy, se);
        for (int j = 0; j < N; j++)
        {
            auto [tx, ty, te] = xye[j];
            if (distMap[ty][tx] <= te)
            {
                is_reach_able[i][j] = true;
            }
        }
    }

    auto res = bfs2(N - 2);

    // for (auto i : res)
    // {
    //     if (i)
    //         printf("O\n");
    //     else
    //         printf("X\n");
    // }

    const bool ans = res[N - 1];
    if (ans)
        printf("Yes");
    else
        printf("No");

    return 0;
}
