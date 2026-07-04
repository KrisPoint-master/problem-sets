#include <bits/stdc++.h>
using namespace std;

int n, l, r;

int main(int argc, char const *argv[])
{
    cin >> n >> l >> r;

    int l1 = l / n, r1 = r / n;
    if (l1 == r1)
    {
        cout << r % n << endl;
        return 0;
    }

    cout << n - 1 << endl;

    return 0;
}
