#include <bits/stdc++.h>
using namespace std;

int n, m;
string min_s[3005], max_s[3005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        string t;
        cin >> t;
        sort(t.begin(), t.end());
        min_s[i] = t;

        reverse(t.begin(), t.end());
        max_s[i] = t;
    }

    for (int i = 1; i <= n; i++)
    {
        bool flag = 1;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;

            if (min_s[i] >= max_s[j])
            {
                flag = 0;
                break;
            }
        }
        cout << flag;
    }
    cout << endl;

    return 0;
}