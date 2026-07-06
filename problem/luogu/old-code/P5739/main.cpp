#include <bits/stdc++.h>
using namespace std;

int n;

int main(int argc, char const *argv[])
{
    cin >> n;
    long long s = 1;
    for (int i = 1; i <= n; i++)
    {
        s *= i;
    }
    cout << s << endl;
    return 0;
}
