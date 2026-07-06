#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn];

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    int t = n;
    int cnt = 0;
    int pos = 0;
    while (t > 0)
    {
        cnt++;
        if (t % 3 == 1 && !pos)
            pos = cnt;
        t -= (t + 2) / 3;
    }
    cout << cnt << " " << pos << endl;
    return 0;
}