#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
int r, a[100], n;
void dfs(int dep)
{
    if (dep > r)
    {
        for (int i = 1; i <= r; i++)
        {
            cout << setw(3) << a[i];
        }
        cout << endl;
        return;
    }
    for (int i = a[dep - 1] + 1; i <= n; i++)
    {
        a[dep] = i;
        dfs(dep + 1);
    }
}
int main()
{
    cin >> n >> r;
    dfs(1);
    return 0;
}