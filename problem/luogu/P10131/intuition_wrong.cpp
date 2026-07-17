#include <bits/stdc++.h>
using namespace std;

int T;

int n;
int a[1000005];
int b[1000005];

void init()
{
    memset(b, 0, sizeof(b));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[a[i]]++;
    }
}

void work()
{
    init();
    set<int> ans;
    if (n < 3)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= 1000000; i++)
    {
        if (b[i] > 2)
        {
            ans.insert(i);
        }
    }
    if (ans.size() == 0)
    {
        cout << -1 << endl;
        return;
    }

    for (auto iter : ans)
    {
        cout << iter << " ";
    }
    cout << endl;
    return;
}

int main(int argc, char const *argv[])
{
    cin >> T;
    while (T--)
    {
        work();
    }
    return 0;
}
