#include <bits/stdc++.h>
using namespace std;

int N;
int A[32][32];

int main()
{
    scanf("%d", &N);
    A[1][1] = 1;
    for (int y = 2; y <= N; y++)
    {
        for (int x = 1; x <= y; x++)
        {
            A[y][x] = A[y - 1][x] + A[y - 1][x - 1];
        }
    }

    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= y; x++)
        {
            printf("%d ", A[y][x]);
        }
        printf("\n");
    }

    return 0;
}