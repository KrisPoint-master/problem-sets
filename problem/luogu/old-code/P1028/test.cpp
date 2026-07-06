#include <bits/stdc++.h>
using namespace std;
int n;
long long f[100005];
long long dfs(long long n)
{
    if (f[n])
        return f[n];
    for (int i = 1; i <= n / 2; i++)
        f[n] += dfs(i);
    f[n] += 1;
    return f[n];
}

int main()
{
    cin >> n;
    cout << dfs(n) << endl;
    return 0;
}
