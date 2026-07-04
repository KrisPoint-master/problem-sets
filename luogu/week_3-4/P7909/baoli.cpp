#include <bits/stdc++.h>
using namespace std;

int n, l, r;

int main(int argc, char const *argv[])
{
    cin >> n >> l >> r;

    int max_ans = INT32_MIN;

    for (int i = l; i <= r; i++) // i -> k
    {
        int ans = i % n;
        max_ans = max(ans, max_ans);
    }

    cout << max_ans << endl;

    return 0;
}
