#include <bits/stdc++.h>
using namespace std;
int pos = -1;
int cnt;
string a, b;

int main()
{
    cin >> a;
    getchar();
    getline(cin, b);
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    a = ' ' + a + ' ';
    b = ' ' + b + ' ';
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    int p = 0;
    while ((p = b.find(a, p)) != string::npos)
    {
        cnt++;
        if (cnt == 1)
            pos = p;
        p++;
    }
    if (cnt)
        cout << cnt << " " << pos;
    else
        cout << -1;
    return 0;
}
