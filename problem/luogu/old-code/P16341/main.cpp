#include <bits/stdc++.h>
using namespace std;

long long n, x;
long long a[1000005];

int main(int argc, char *argv[])
{
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            long long sum = 1;
            for (int k = i; k <= j; k++)
            {
                sum *= a[k];
            }
            if (sum == x)
            {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << "-1" << endl;
    return 0;
}