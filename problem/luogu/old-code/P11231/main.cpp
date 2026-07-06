#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn], b[maxn * 10];

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[a[i]]++;
    }
    int maxl = 0;
    for (int i = 1; i <= 100000; i++)
        if (b[i] >= maxl)
            maxl = b[i];
    cout << maxl << endl;

    return 0;
}