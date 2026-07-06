#include <bits/stdc++.h>
using namespace std;

long long fib[100];

void init()
{
    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3; i <= 90; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

int main(int argc, char const *argv[])
{
    init();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int f = 0;
        for (int i = 90; i >= 1; i--)
        {
            cout << fib[i] << endl;
            if (fib[i] < n)
            {
                f = fib[i];
                break;
            }
        }
        cout << n - f << endl;
    }
    return 0;
}
