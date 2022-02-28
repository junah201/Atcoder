#include <stdio.h>

int N;
char map[1002][1002];

int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

int check(int x, int y)
{
    int result = 0;
    for (int i = 0; i < 8; i++)
    {
        int rx = x;
        int ry = y;
        int value = 0;
        int sign = 0;
        if (dx[i] == 0)
        {
            while (rx == x && ry != y + 6 * dy[i] && ry >= 0 && rx >= 0 && rx < N && ry < N)
            {
                if (map[ry][rx] == '#')
                    value++;
                else
                    sign++;
                rx += dx[i];
                ry += dy[i];
            }
        }
        else if (dy[i] == 0)
        {
            while (rx != x + 6 * dx[i] && ry == y && ry >= 0 && rx >= 0 && rx < N && ry < N)
            {
                if (map[ry][rx] == '#')
                    value++;
                else
                    sign++;
                rx += dx[i];
                ry += dy[i];
            }
        }
        else
        {
            while (rx != x + 6 * dx[i] && ry != y + 6 * dy[i] && ry >= 0 && rx >= 0 && rx < N && ry < N)
            {
                if (map[ry][rx] == '#')
                    value++;
                else
                    sign++;
                rx += dx[i];
                ry += dy[i];
            }
        }
        rx -= dx[i];
        ry -= dy[i];
        int temp = 6 - sign - value;
        if (value > result)
        {
            int A = ((x - temp * dx[i] >= 0 && x - temp * dx[i] < N) && (y - temp * dy[i] >= 0 && y - temp * dy[i] < N));
            int B = ((rx + temp * dx[i] >= 0 && rx + temp * dx[i] < N) && (ry + temp * dy[i] >= 0 && ry + temp * dy[i] < N));
            if (A || B)
                result = value;
        }
    }
    return result;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%s", map[i]);

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (map[y][x] == '#')
            {
                if (check(x, y) >= 4)
                {
                    printf("Yes");
                    return 0;
                }
            }
        }
    }
    printf("No");
    return 0;
}