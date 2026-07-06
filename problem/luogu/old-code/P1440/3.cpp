#include <bits/stdc++.h>
using namespace std;

int a[2000005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    deque<int> dq;

    for (int i = 1; i <= n; ++i)
    {
        if (i == 1)
        {
            cout << "0\n";
        }
        else
        {
            if (!dq.empty() && dq.front() < i - m)
            {
                dq.pop_front();
            }
            cout << a[dq.front()] << "\n";
        }
        while (!dq.empty() && a[dq.back()] >= a[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    return 0;
}