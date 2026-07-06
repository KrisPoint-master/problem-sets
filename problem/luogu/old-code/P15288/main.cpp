#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int T, n, m;
int a[maxn];

int next_num_pos(int n, int pos)
{
    if (pos == n)
        return 0;
    return pos++;
}
int prev_num_pos(int n, int pos)
{
    if (pos == 0)
        return n;
    return pos--;
}

int check(int *a, int k)
{
    int sum = 0;
    int prevnum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int k = prev_num_pos(n, i), l = 1; l == k; k = prev_num_pos(n, k), l++)
        {
            sum += a[k];
        }
        for (int k = next_num_pos(n, i), l = 1; l == k; k = next_num_pos(n, k), l++)
        {
            sum += a[k];
        }
        sum += a[i];
        if (i == 1)
            continue;
        if (prevnum == sum)
            continue;
        return 0;
    }
    return 1;
}

void work()
{
    int cnt = 0;
    for (int k = 1; k <= m; k++)
    {
        do
        {
            int flag = check(a, k);
            if (flag)
                cnt++;
        } while (next_permutation(a + 1, a + 1 + n));
    }
    cout << cnt << endl;
}

int main(int argc, char const *argv[])
{
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        work();
    }
    return 0;
}