#include <bits/stdc++.h>
using namespace std;

long long a;
long long b;
long long minn = 1e10;
int main()
{
    cin >> a >> b;
    if (b == 1)
    {
        cout << 0;
        return 0;
    }
    if (a <= b)
    {
        cout << b - a;
        return 0;
    }
    for (int i = 1; i <= b * 2; i++)
    {
        long long s;
        s = min(a % i, i - a % i) + abs(b - i);
        minn = min(s, minn);
    }
    cout << minn;
    return 0;
}
