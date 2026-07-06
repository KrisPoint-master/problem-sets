#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int n, m;
int a[105][105];
int dx[9]{0, -1, 1, 0, 0, -1, 1, -1, 1};
int dy[9]{0, 0, 0, 1, -1, 1, 1, -1, -1};

int main(int argc, char **argv)
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            if (c == '*')
            {
                a[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int cnt = 0;
            if (a[i][j])
            {
                cout << "*";
                continue;
            }
            for (int k = 1; k <= 8; k++)
            {
                if (a[i + dx[k]][j + dy[k]])
                {
                    cnt++;
                }
            }
            cout << cnt;
        }
        cout << endl;
    }

    return 0;
}