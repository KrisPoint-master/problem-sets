#include <bits/stdc++.h>
using namespace std;

int b[1000005];
int b2[1000005];
int cnt;
int cnt_special_number;

int flag[100005];
int special_number[100005];
int f[100005];

int is_special_number(long long x)
{
    cnt = 0;
    memset(b, 0, sizeof(b));
    memset(b2, 0, sizeof(b2));

    long long t = x;
    while (t)
    {
        cnt++;
        b[cnt] = b2[cnt] = t % 10;
        t /= 10;
    }
    reverse(b + 1, b + 1 + cnt);
    for (int i = 1; i <= cnt; i++)
    {
        if (b[i] != b2[i])
        {
            return 0;
        }
    }
    return 1;
}

void init()
{
    memset(special_number, 0, sizeof special_number);
    cnt_special_number = 0;
    for (int i = 1; i < 1005; i++)
    {
        flag[i] = is_special_number(i);
        if (flag[i])
            special_number[++cnt_special_number] = i;
    }
    // cnt_special_number is len of special_number
}

int dfs(int s, int who) // who : 0 : Bes , 1: Els, return 1 current player can win
{
    if (s == 0)
        return false;
    if (f[s] != -1)
        return f[s];
    for (int i = 1; i <= cnt_special_number; i++)
    {
        if (special_number[i] > s)
            break;
        if (dfs(s - special_number[i], who ^ 1) == 0)
            return f[s] = true;
    }
    return f[s] = false;
}

void work()
{
    int S;
    cin >> S;
    memset(f, -1, sizeof(f));
    // cout << S << "    " << is_special_number(S) << "     ";
    cout << ((dfs(S, 0)) ? 'B' : 'E');
    cout << '\n';
}

int main(int argc, char const *argv[])
{
    init();
    int T;
    cin >> T;
    while (T--)
    {
        work();
    }
    return 0;
}
