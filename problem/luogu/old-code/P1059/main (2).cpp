#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn];
int b[maxn];

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i + 1];
        b[a[i + 1]]++;
        s.insert(a[i + 1]);
    }
    cout << s.size() << endl;
    for (int i = 0; i <= 1005; i++)
    {
        if (b[i])
            cout << i << " ";
    }

    return 0;
}