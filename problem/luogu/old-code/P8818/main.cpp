#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn];
int b[maxn];
int n, m, q;

void read(int *a, int n)
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

void init()
{
    cin >> n >> m >> q;
    read(a, n);
    read(b, m);
}

void work()
{
    int l1, r1, l2, r2;
    while (q--)
    {
        cin >> l1 >> r1 >> l2 >> r2;
        int maxans = INT32_MIN, minans = INT32_MAX;
        /*
        for (int x = l1; x <= r1; x++)
        {
            for (int y = l2; y <= r2; y++)
            {
                int ans = a[x] * b[y]; // c_{xy}
                maxans = max(ans, maxans);
                minans = min(ans, minans);
            }
        }
        cout << maxans <<  " " << minans << endl;
        */
        for (int i = l1; i <= r1; i++)
        {
            for (int j = l2; j <= r2; j++)
            {
                minans = min(a[i] * b[j], minans);
            }
            maxans = max(minans, maxans);
            minans = INT32_MAX;
        }
        cout << maxans << endl;
    }
}

int main(int argc, char **argv)
{
    init(), work();
    return 0;
}