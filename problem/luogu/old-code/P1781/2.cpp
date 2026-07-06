#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> a;

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i].append(to_string(i));
    }

    sort(a.begin(), a.end());

    cout << a[n - 1][a.size()] << endl;
    cout << a[n - 1] << endl;

    return 0;
}
