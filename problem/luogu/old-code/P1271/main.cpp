#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;

int a[maxn];

int main(int argc, char **argv)
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + m + 1);

    for (int i = 1; i <= m; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}