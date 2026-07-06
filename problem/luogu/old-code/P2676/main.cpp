#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn];

int main(int argc, char **argv)
{
    int n, s = 0, b;
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n, greater<int>());
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt++;
        s += a[i];
        if (s >= b)
            break;
    }

    cout << cnt << endl;

    return 0;
}