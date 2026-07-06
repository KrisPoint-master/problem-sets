#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;

int a[maxn];

int main(int argc, char **argv)
{
    int max = -2, max2 = -1;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            if (a[j] == 0)
                continue;
            s.insert(a[i] % a[j]);
        }
    }
    if (s.size() < 2)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<int> v(maxn);
    for (auto l : s)
    {
        v.push_back(l);
    }
    sort(v.begin(), v.end(), greater<int>());
    cout << v[1] << endl;

    return 0;
}