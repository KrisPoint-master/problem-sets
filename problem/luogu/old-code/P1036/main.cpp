#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[25];
int ans;
bool isprime(int a)
{
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}
void dfs(int step, int sum, int start)
{
    if (step == k)
    {
        if (isprime(sum))
            ans++;
        return;
    }
    for (int i = start; i < n; i++)
    {
        dfs(step + 1, sum + a[i], i + 1);
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}