#include <bits/stdc++.h>
using namespace std;

int dm[13]{
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(int argc, char const *argv[])
{
    int m, d, cnt = 0;
    char c;
    cin >> m >> c >> d;
    if (m > 12)
    {
        cnt++;
    }
    if (d > dm[m])
    {
        cnt++;
    }
    if (cnt)
        if (m <= 20)
        {
            if (d <= 31)
                cnt--;
        }
    int ml = m % 10;
    int mk = m / 10;

    cout << cnt << endl;
    return 0;
}
