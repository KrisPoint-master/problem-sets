#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn];

int main(int argc, char **argv)
{
    set<string> s;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        s.insert(str);
    }

    cout << 52 - s.size() << endl;

    return 0;
}