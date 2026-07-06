#include <bits/stdc++.h>
using namespace std;

int n, sum, ave, cnt1, pos;
int a[100005], b[100005], b2[100005];

void init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    ave = sum / n;
    for (int i = 1; i <= n; i++)
    {
        b[i] = a[i] - ave;
        if (b[i] == 0)
            pos = i;
    }
}

int main(int argc, char const *argv[])
{
    init();
    for (int i = 1; i <= n; i++)
    {
        if (b[i] != 0)
        {
            b[i + 1] += b[i];
            b[i] = 0;
            cnt1++;
        }
    }
    cout << cnt1 << endl;
    return 0;
}
