#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn];
int n, m;

int main(int argc, char **argv)
{
    cin >> n >> m;
    int pos = 1;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
        if (a[i] > a[1])
            pos++;
    }
    int k = ceil((double)pos / (double)n);
    int l;
    if (k % 2 == 0)
    {
        l = pos % n;
    }
    else
    {
        l = n - (pos % n);
    }

    cout << k << " " << l << endl;

    return 0;
}