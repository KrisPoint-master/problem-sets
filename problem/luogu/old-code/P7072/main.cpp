#include <bits/stdc++.h>
using namespace std;

int a[1000005];
int n, w;

int main(int argc, char const *argv[])
{
    cin >> n >> w;
    int p = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p = max(1.0, floor((double)i * (double)w / (double)100));
        sort(a + 1, a + 1 + n, greater<int>());
        cout << a[p] << " ";
    }

    return 0;
}
