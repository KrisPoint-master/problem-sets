#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;
int t[maxn];
int sum;
int main(int argc, char **argv)
{
    int n, T;
    cin >> n >> T;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (t[i + 1] - t[i] >= T)
            sum += T;
        else
            sum += t[i + 1] - t[i];
    }

    cout << sum + T << endl;

    return 0;
}