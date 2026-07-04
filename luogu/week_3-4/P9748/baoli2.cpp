#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    int days = 0, nth_day = 0;

    while (!a.empty())
    {
        days++;
        vector<int> b;
        for (int i = 0; i < (int)a.size(); i++)
        {
            if (i % 3 == 0)
            {
                if (a[i] == n && nth_day == 0)
                    nth_day = days;
            }
            else
            {
                b.push_back(a[i]);
            }
        }
        a = b;
    }

    cout << days << " " << nth_day << endl;
    return 0;
}
