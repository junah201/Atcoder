#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> inp;

int main()
{
    scanf("%d", &N);
    inp.resize(N + 1, 0);
    for (int i = 1; i <= N; i++)
        scanf("%d", &inp[i]);
    scanf("%d", &Q);
    for (int i = 0, L, R, ans; i < Q; i++)
    {
        scanf("%d %d", &L, &R);

        vector<int> cnt;
        cnt.resize(N + 1, 0);
        ans = 0;
        for (int j = L; j <= R; j++)
        {
            cnt[inp[j]]++;

            while (cnt[inp[j]] >= 2)
            {
                cnt[inp[j]] -= 2;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
