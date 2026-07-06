#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int n;
int a[maxn][10];

int next_num(int x)
{
    if (x == 9)
        return 0;
    return x + 1;
}

int prev_num(int x)
{
    if (x == 0)
        return 9;
    return x - 1;
}

int maxans;

int f1(int ans)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += 10;
    }
}

int f2(int ans)
{
}

void f(int ans)
{
    ans = f1(ans) + f2(ans);
}

int main(int argc, char **argv)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cin >> a[i][j];
        }
    }

    f(0);

    return 0;
}