#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int n, m;
int a[maxn];
int s[maxn];

int main(int argc, char **argv)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << (a[r] - a[l - 1]) << endl;
    }

    return 0;
}