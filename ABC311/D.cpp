/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int Y, X;
vector<vector<char>> graph;
vector<vector<char>> is_possible;
vector<vector<vector<char>>> visited;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

signed main()
{
    scanf("%lld %lld", &Y, &X);
    graph.resize(Y, vector<char>(X));
    is_possible.resize(Y, vector<char>(X, 0));
    visited.resize(Y, vector<vector<char>>(X, vector<char>(4, false)));

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            scanf(" %1c", &graph[y][x]);
        }
    }

    queue<pair<int, int>> q;
    is_possible[1][1] = true;
    q.emplace(1, 1);

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            if (visited[y][x][i])
                continue;

            visited[y][x][i] = true;

            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= X || ny < 0 || ny >= Y)
                continue;

            if (graph[ny][nx] == '#')
                continue;

            while (true)
            {
                if (nx < 0 || nx >= X || ny < 0 || ny >= Y)
                {
                    q.emplace(nx - dx[i], ny - dy[i]);
                    break;
                }

                if (graph[ny][nx] == '#')
                {
                    q.emplace(nx - dx[i], ny - dy[i]);
                    break;
                }

                is_possible[ny][nx] = true;

                nx += dx[i];
                ny += dy[i];
            }
        }
    }

    int ans = 0;

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            ans += is_possible[y][x];
        }
    }

    printf("%lld", ans);

    return 0;
}