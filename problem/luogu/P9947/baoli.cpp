#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001];
int ans[1001];
map<int, bool> mp;

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < a[1]; i++)
    {
        ans[1] = i;
        mp[i] = 1;
        for (int j = 2; j <= n; j++)
        {
            ans[j] = a[j - 1] - ans[j - 1];
            mp[ans[j]] = 1;
        }
        bool flag = 1;
        for (int j = 1; j <= n; j++)
        {
            if (!mp[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << ans[j] << " ";
            }
            return 0;
        }
        for (int j = 1; j <= n; j++)
        {
            mp[j] = 0;
        }
    }
}
