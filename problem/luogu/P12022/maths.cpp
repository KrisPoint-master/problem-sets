#include <bits/stdc++.h>
using namespace std;

int n, m;

enum WIN_LOSE_DRAW
{
    DRAW = 1,
    WIN,
    LOSE
};

int hoof_symbol_rules[3005][3005];

#define int long long

int s1[10005];
int s2[10005];

#ifdef DEBUG
void test1()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << hoof_symbol_rules[i][j] << " ";
        }
        cout << endl;
    }
}
#else
void test1() {}
#endif

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            char c;
            cin >> c;
            if (c == 'D')
            {
                hoof_symbol_rules[i][j] = DRAW;
                hoof_symbol_rules[j][i] = DRAW;
                continue;
            }
            if (c == 'W')
            {
                hoof_symbol_rules[i][j] = WIN;
                hoof_symbol_rules[j][i] = LOSE;
                continue;
            }
            if (c == 'L')
            {
                hoof_symbol_rules[i][j] = LOSE;
                hoof_symbol_rules[j][i] = WIN;
                continue;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> s1[i] >> s2[i];
    }
}

int check(int p1, int p2)
{
    if (hoof_symbol_rules[p1][p2] == WIN)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void solve(int ell, int elr)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!check(i, ell))
        {
            cnt++;
            continue;
        }
        if (!check(i, elr))
            cnt++;
    }
    cout << n * n - cnt * cnt << endl;
}

void work()
{
    for (int i = 1; i <= m; i++)
    {
        int l = s1[i];
        int r = s2[i];
        solve(l, r);
    }
}

signed main()
{
    init();
    work();
    return 0;
}
