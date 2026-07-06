#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
string a[maxn];
int n;
bool cmp(string a, string b)
{
    return (a + b) > (b + a);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    string ans = "";
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}
