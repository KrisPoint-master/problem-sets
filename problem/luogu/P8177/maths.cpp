#include <bits/stdc++.h>
using namespace std;

int T;

int n, a, d;

int main(int argc, char const *argv[])
{
    cin >> T;
    while (T--)
    {
        cin >> n >> a >> d;
        vector<int> num(n + 5, 0);
        for (int i = 0; i < n; i++)
        {
            num[i] = a + i * d;
        }
    }
    return 0;
}
