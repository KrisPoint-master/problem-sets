#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAXN = 3000005;
int a[MAXN];
int f[MAXN];
stack<int> s;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        while (!s.empty() && a[i] > a[s.top()])
        {
            f[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << f[i] << " ";
    }

    return 0;
}