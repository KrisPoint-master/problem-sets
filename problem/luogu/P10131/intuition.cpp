#include <bits/stdc++.h>
using namespace std;

int T;

int n;
int a[1000005];
int b[1000005];
set<int> ans;

int check(int idx)
{
    if (idx > 1 && a[idx] == a[idx - 1])
        return 1;
    if (idx < n && a[idx] == a[idx + 1])
        return 1;
    if (idx > 2 && a[idx] == a[idx - 2])
        return 1;
    if (idx < n - 1 && a[idx] == a[idx + 2])
        return 1;
    return 0;
}

void init()
{
    ans.clear();
    memset(b, 0, sizeof(b));
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (check(i))
            ans.insert(a[i]);
    }
}

void work()
{
    init();
    if (ans.size() == 0)
    {
        cout << "-1" << endl;
        return;
    }
    for_each(ans.begin(), ans.end(), [](auto d_ans)
             { cout << d_ans << " "; });
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
