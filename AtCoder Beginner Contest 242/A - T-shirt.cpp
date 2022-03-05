#include <bits/stdc++.h>
using namespace std;

int A, B, C, X;

int main()
{
    scanf("%d %d %d %d", &A, &B, &C, &X);
    if (X <= A)
    {
        printf("%.12lf", 1.0);
        return 0;
    }
    else if (X > B)
    {
        printf("%.12lf", 0.0);
        return 0;
    }
    else
    {
        printf("%.12lf", C * (1.0) / (B - A));
        return 0;
    }
    return 0;
}