#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn];

int main(int argc, char **argv)
{
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << ' ';
    }

    return 0;
}