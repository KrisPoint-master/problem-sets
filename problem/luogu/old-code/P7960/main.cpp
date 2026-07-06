#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 100;
int T, x, ls;
int f[N], nx[N];
bool check(int x)
{
    while (x)
    {
        if (x % 10 == 7)
            return 1;
        x /= 10;
    }
    return 0;
}
void init()
{
    for (int i = 1; i <= N - 10; i++)
    {
        if (f[i])
            continue;
        if (check(i))
        {
            for (int j = i; j <= N - 10; j += i)
                f[j] = 1;
            continue;
        }
        nx[ls] = i;
        ls = i;
    }
}
int main()
{
    init();
    cin >> T;
    while (T--)
    {
        cin >> x;
        if (f[x])
            cout << "-1" << endl;
        else
            cout << nx[x] << endl;
    }
    return 0;
}
