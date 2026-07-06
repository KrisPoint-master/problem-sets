
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;

int a[maxn];

int main(int argc, char **argv)
{
    int cnt = 0;
    string s;
    cin >> s;
    for (auto c : s)
    {
        if ('0' <= c && c <= '9')
        {
            a[++cnt] = c - '0';
        }
    }
    sort(a + 1, a + cnt + 1, greater<int>());
    for (int i = 1; i <= cnt; i++)
    {
        cout << a[i];
    }

    return 0;
}