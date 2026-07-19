#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
    cin >> n >> s;

    int ans = 0;
    char last = '.';

    for (int i = 0; i < n; i += 2)
    {
        if (s[i] != s[i + 1] && s[i] != last)
        {
            ans++;
            last = s[i];
        }
    }

    if (last == 'H')
    {
        ans--;
    }

    cout << ans << '\n';

    return 0;
}