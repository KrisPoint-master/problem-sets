#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 5;
const int mod = 10007;

int n, m, k;
int a[maxn];
int target[maxn];

struct machine
{
    int i = 0;
    int o;
    long long x, y;

    void run_task();
} mach[maxn];
string s;
void machine::run_task()
{
    if (o == 1)
    {
        target[x] += y;
        target[x] %= mod;
    }

    cout << s << "|-- FLAGS: " << i << "   X: " << x << "   Y: " << y << "    Now a[i]: ";
    for (int i = 1; i <= n; i++)
    {
        cout << target[i] << " ";
    }
    cout << endl;

    if (o == 2)
        for (int i = x; i <= y; i++)
        {
            s.append("   ");
            mach[i].run_task();
            s.erase(s.size() - 3);
        }
}

void init()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        mach[i].i = i;
        cin >> mach[i].o >> mach[i].x >> mach[i].y;
    }
}

void work()
{
    for (int i = 1; i <= k; i++)
    {
        mach[a[i]].run_task();
    }
    for (int i = 1; i <= n; i++)
    {
        cout << target[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    work();

    return 0;
}
