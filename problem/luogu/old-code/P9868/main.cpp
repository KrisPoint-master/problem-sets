#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<string, int>> a(3000 + 5);
vector<pair<int, int>> b(3000 + 5);
vector<bool> bk(3005 + 5);

bool cmp(char a, char b)
{
    return a > b;
}

int main(int argc, const char **argv)
{
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
        a[i] = make_pair(t, i);
        sort(t.begin(), t.end());
        b[i] = make_pair(t[0], t[t.size() - 1]);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(a[i].first.begin(), a[i].first.end());
        bool flag = 1;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            sort(a[j].first.begin(), a[j].first.end(), cmp);
            if (a[i].first > a[j].first)
            {
                flag = 0;
                break;
            }
        }
        cout << flag;
    }

    return 0;
}