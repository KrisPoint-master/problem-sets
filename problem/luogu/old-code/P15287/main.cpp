#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    long long n;
    cin >> n;
    long long k = n / 2 + 1;
    if (n == 1)
    {
        cout << -1 << endl;
        goto end;
    }
    cout << k << endl;
end:
    return 0;
}
