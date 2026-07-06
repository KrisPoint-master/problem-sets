#include <bits/stdc++.h>
using namespace std;
const int max_n = 20 + 5;
string s[max_n];
bool cmp(const string &A, const string &B)
{
    return A + B > B + A;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> s[i];
    sort(s + 1, s + n + 1, cmp);
    for (int i = 1; i <= n; ++i)
        cout << s[i];
    cout << "\n";
    return 0;
}
