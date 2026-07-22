#include <bits/stdc++.h>
using namespace std;

int ans;

int init(char a, char b)
{
    if (a == 'N' && b == 'E')
        return 1;
    if (a == 'E' && b == 'S')
        return 1;
    if (a == 'S' && b == 'W')
        return 1;
    if (a == 'W' && b == 'N')
        return 1;
    return -1;
}

int main()
{
    int n;
    string s;
    cin >> n;
    while (n--)
    {
        ans = 0;
        cin >> s;
        for (int i = 1; i <= s.length() - 1; i++)
        {
            if (s[i - 1] != s[i])
                ans += init(s[i - 1], s[i]);
        }
        if (ans > 0)
            cout << "CW" << endl;
        else
            cout << "CCW" << endl;
    }
}
