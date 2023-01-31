/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int N, min_number = INT_MAX, ans = 0;
vector<int> A;
// 2, 3, etc
vector<tuple<int, int, int>> B;

int main()
{
    scanf("%d", &N);
    A.resize(N + 2);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
        min_number = min(min_number, A[i]);
    }
    for (int i = 0; i < N; i++)
    {
        if (A[i] % min_number != 0)
        {
            printf("-1");
            return 0;
        }
        int tmp = A[i] / min_number;
        while (A[i] > min_number)
        {
            if (tmp % 2 == 0)
            {
                tmp /= 2;
                A[i] /= 2;
            }
            else if (tmp % 3 == 0)
            {
                tmp /= 3;
                A[i] /= 3;
            }
            ans++;
        }
    }

    printf("%d", ans);
    return 0;
}