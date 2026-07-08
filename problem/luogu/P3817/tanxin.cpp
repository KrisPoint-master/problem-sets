#include <bits/stdc++.h>
using namespace std;

long long n, x;
long long a[100005];

int main(int argc, char const *argv[])
{
    cin >> n >> x;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    long long cnt = 0;
    for (long long i = 1; i <= n; i++)
    {
        while (a[i] + a[i - 1] > x)
        {
            a[i]--;
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
