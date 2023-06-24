/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
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

int N;
char A[2 * 100002];
stack<char> S;

signed main()
{
    scanf("%lld", &N);
    scanf("%s", A);

    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] == '(')
        {
            cnt++;
            S.emplace(A[i]);
        }
        else if (A[i] == ')')
        {
            if (cnt)
            {
                while (true)
                {
                    if (S.top() == '(')
                    {
                        S.pop();
                        break;
                    }
                    S.pop();
                }
                cnt--;
            }
            else
            {
                S.emplace(A[i]);
            }
        }
        else
        {
            S.emplace(A[i]);
        }
    }

    stack<char> ans;
    while (!S.empty())
    {
        ans.emplace(S.top());
        S.pop();
    }

    while (!ans.empty())
    {
        printf("%c", ans.top());
        ans.pop();
    }

    return 0;
}