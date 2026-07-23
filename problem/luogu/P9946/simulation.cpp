#include <bits/stdc++.h>
using namespace std;

int n, k;
string a[1000005];

int main(int argc, char const *argv[])
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        string &s = a[i];
        int len = s.size();
        if (cnt + len > k)
        {
            putchar('\n');
            cout << s;
            cnt = len;
        }
        else
        {
            if (cnt > 0) putchar(' ');
            cout << s;
            cnt += len;
        }
    }

    return 0;
}
