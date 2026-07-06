#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;

int T;

struct car
{
    int d, v, a;
    bool isoutv = 0;
} c[maxn];
bool p[maxn];
int ppos[maxn];

int special_task_A = 1;
int n, m, l, v;
long long cnt_A = 0;

void init()
{
    cin >> n >> m >> l >> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i].d >> c[i].v >> c[i].a;
        if (c[i].a != 0)
            special_task_A = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int temp;
        cin >> temp;
        p[temp] = 1;
        ppos[i] = temp;
    }
}

void fac_spe_task_A()
{
    int can_close = m - 1;
    int t = ppos[m];
    for (int j = 1; j <= n; j++)
        if (c[j].d <= t && c[j].v > v)
            cnt_A++;
    cout << cnt_A << " " << can_close << endl;
}

void work()
{
    init();
    if (special_task_A)
        fac_spe_task_A();
}

int main(int argc, char **argv)
{
    cin >> T;
    while (T--)
        work();
    return 0;
}