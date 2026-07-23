#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define N
using namespace std;
string S, S0;
int n;

inline ll read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -f;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

int main()
{
    n = read();
    cin >> S;
    for (int k = 1; k <= n; k++)
    {
        bool flag = 0;
        for (int j = 0; j < n - k; j++)
        {
            S0 = S.substr(j, k);
            if (S.find(S0, j + 1) <= 100)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            printf("%d\n", k);
            break;
        }
    }
    return 0;
}
