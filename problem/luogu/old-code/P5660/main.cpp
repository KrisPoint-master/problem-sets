#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int main(int argc, char **argv)
{
    string a;
    cin >> a;
    int cnt = 0;
    for (auto s : a)
    {
        if (s == '1')
            cnt++;
    }
    cout << cnt << endl;

    return 0;
}