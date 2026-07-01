#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

int a[maxn];
int l[maxn];
int n;

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        l[i] = l[i - 1] + a[i];
    }

    auto get_sum = [](int l1, int r1)
    {
        return l[r1] - l[l1 - 1];
    };

    int max_ans = INT32_MIN;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            // i,j -> l,r
            int sum = get_sum(i, j);
            max_ans = max(max_ans, sum);
        }
    }

    cout << max_ans << endl;

    return 0;
}
