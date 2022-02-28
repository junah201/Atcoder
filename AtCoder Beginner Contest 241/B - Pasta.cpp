#include <stdio.h>

int N, M;
int A[1002], B[1002];
int temp;

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", &A[i]);
    for (int i = 1, is = 0; i <= M; i++)
    {
        is = 0;
        scanf("%d", &temp);
        for (int i = 1; i <= N; i++)
            if (A[i] == temp)
            {
                A[i] = -1;
                is = 1;
                break;
            }
        if (is == 0)
        {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}