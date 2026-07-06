#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn];

int main(int argc, char **argv)
{
    int n, x;
    cin >> n >> x;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (1 <= i && i < 10)
        {
            if (i == x)
            {
                cnt++;
            }
        }
        else if (10 <= i && i < 100)
        {
            int l = i / 10;
            int k = i % 10;
            if (l == x)
            {
                cnt++;
            }
            if (k == x)
                cnt++;
        }
        else if (100 <= i && i < 1000)
        {
            int l = i / 100;
            int k = (i % 100) / 10;
            int j = i % 10;
            if (l == x)
                cnt++;
            if (k == x)
                cnt++;
            if (j == x)
                cnt++;
        }
        else if (1000 <= i && i < 10000)
        {
            int l = i / 1000;
            int k = (i % 1000) / 100;
            int j = (i % 1000) / 10;
            int h = i % 1000;
            if (l == x)
                cnt++;
            if (k == x)
                cnt++;
            if (j == x)
                cnt++;
            if (h == x)
            {
                cnt++;
            }
        }
        else if (10000 <= i && i < 100000)
        {
            int l = i / 10000;
            int k = i % 10000 / 1000;
            int j = i % 10000 / 100;
            int h = i % 10000 / 10;
            int g = i % 10000;
            if (l == x)
                cnt++;
            if (k == x)
                cnt++;
            if (j == x)
                cnt++;
            if (h == x)
                cnt++;
            if (g == x)
            {
                cnt++;
            }
        }
        else if (100000 <= i && i < 1000000)
        {
            int l = i / 100000;
            int k = i % 100000 / 10000;
            int j = i % 100000 / 1000;
            int h = i % 100000 / 100;
            int g = i % 100000 / 10;
            int f = i % 100000;
            if (l == x)
                cnt++;
            if (k == x)
                cnt++;
            if (j == x)
                cnt++;
            if (h == x)
                cnt++;
            if (g == x)
                cnt++;
            if (f == x)
            {
                cnt++;
            }
        }
        else if (1000000 <= i && i < 10000000)
        {
            int l = i / 1000000;
            int k = i % 1000000 / 100000;
            int j = i % 1000000 / 10000;
            int h = i % 1000000 / 1000;
            int g = i % 1000000 / 100;
            int f = i % 100000 / 10;
            int d = i % 100000;
            if (l == x)
                cnt++;
            if (k == x)
                cnt++;
            if (j == x)
                cnt++;
            if (h == x)
                cnt++;
            if (g == x)
                cnt++;
            if (f == x)
            {
                cnt++;
            }
            if (d == x)
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}