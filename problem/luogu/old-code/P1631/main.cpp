#include <bits/stdc++.h>
using namespace std;
int n, a[100005], b[100005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; (i - 1) * (j - 1) <= n && j <= n; ++j)
            q.push(a[i] + b[j]);
    for (int i = 0; i < n; ++i)
    {
        cout << q.top() << " ";
        q.pop();
    }
    return 0;
}
