#include <bits/stdc++.h>
using namespace std;

int b[100005];

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= m; i++)
    {
        next_permutation(b + 1, b + n + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << b[i] << " ";
    }
    
    return 0;
}