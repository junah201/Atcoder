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

int N, Q, query_cnt, init_value;
int op, x, idx;
vector<ll> A;
vector<int> D;

int main()
{
    scanf("%d", &N);
    A.resize(N + 2);
    D.resize(N + 2);

    for (int i = 0; i < N; i++)
        scanf("%lld", &A[i]);

    scanf("%d", &Q);

    // 1번 쿼리 단위로 끊어서 처리하기
    for (int i = 0; i < Q; i++)
    {
        scanf("%d", &op);

        if (op == 1)
        {
            query_cnt++;
            scanf("%d", &init_value);
        }
        else if (op == 2)
        {
            scanf("%d %d", &idx, &x);
            if (D[idx - 1] != query_cnt)
            {
                D[idx - 1] = query_cnt;
                A[idx - 1] = init_value;
            }
            A[idx - 1] += x;
        }
        else if (op == 3)
        {
            scanf("%d", &idx);
            if (D[idx - 1] != query_cnt)
            {
                D[idx - 1] = query_cnt;
                A[idx - 1] = init_value;
            }
            printf("%lld\n", A[idx - 1]);
        }
    }

    return 0;
}