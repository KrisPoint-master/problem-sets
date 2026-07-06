#include <bits/stdc++.h>
using namespace std;

int b[100005];

int numfac(int x)
{
    int len = 0;
    while (x != 0)
    {
        b[++len] = x % 2;
        x /= 2;
    }
    return len;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int len = numfac(n);
    vector<int> a;
    for (int i = 1; i <= len; i++)
    {
        if (b[i])
            a.push_back(pow(2, i - 1));
    }

    if (a.size() == 0 || b[1] == 1)
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = a.size() - 1; i >= 0; i--)
    {
        cout << a[i] << " ";
    }

    return 0;
}
