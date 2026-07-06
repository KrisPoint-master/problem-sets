#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

constexpr int UP = 1;
constexpr int DOWN = -1;

int n;
int h[maxn];

int main(int argc, char const *argv[])
{
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    int flag = 0; // prev_flag
    int ans = 1;

    for (int i = 2; i <= n; i++)
    {
        if (h[i] == h[i - 1])
        {
            continue;
        }
        int now_flag = (h[i] > h[i - 1]) ? UP : DOWN;
        if (flag == 0 || now_flag != flag)
        {
            ans++;
            flag = now_flag;
        }
    }

    cout << ans << endl;

    return 0;
}
