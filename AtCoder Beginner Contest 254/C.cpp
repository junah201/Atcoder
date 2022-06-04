#include <bits/stdc++.h>
using namespace std;

int N, K;

vector<int> inp, order;

map<int, multiset<int>> m;

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0, tmp; i < N; i++)
    {
        scanf("%d", &tmp);
        inp.push_back(tmp);
        order.push_back(tmp);
    }

    sort(order.begin(), order.end());

    for (int i = 0; i < N; i++)
    {
        if (i != N - 1 && order[i] == order[i + 1])
            continue;
        auto [ts, te] = equal_range(order.begin(), order.end(), order[0]);
        int start = ts - order.begin();
        int end = te - order.begin();
        for (int j = start; j < end; j++)
        {
            m[order[i]].insert(j % K);
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (m[inp[i]].find(i % K) == m[inp[i]].end())
        {
            printf("No");
            return 0;
        }
        m[inp[i]].erase(m[inp[i]].find(i % K));
    }
    printf("Yes\n");
    return 0;
}