#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    int p = n / m;
    int q = n % m;

    vector<int> a(m);
    for_each(a.begin(), a.end(), [a, p](int &o)
             { o = p; });

    for (int i = 0; q > 0; i++, q--, a[i]++)
        ;
    sort(a.begin(), a.end());
    for_each(a.begin(), a.end(), [](int a)
             { cout << a << " "; });

    cout
        << endl;

    return 0;
}
