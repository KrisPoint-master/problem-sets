#include <bits/stdc++.h>
using namespace std;
int n, t, l, ans[10005], maxans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> i >> l;
        int tmp = 0;
        while (1)
        {
            cin >> t;
            if (t == 0)
                break;
            tmp = max(ans[t], tmp);
        }
        ans[i] = tmp + l;
        maxans = max(ans[i], maxans);
    }
    cout << maxans << endl;
    return 0;
}
