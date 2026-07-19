#include <bits/stdc++.h>
using namespace std;

map<char, int> m;
map<char, int> mc;

int a[3][3];
// int b[3][3];

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char c;
            cin >> c;
            m[c]++;
            a[i][j] = c;
        }
    }
    int cnt = 0; // green
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char c;
            cin >> c;
            mc[c]++;
            if (a[i][j] == c)
            {
                cnt++;
                m[c]--;
                mc[c]--;
            }
        }
    }
    int cnt2 = 0;

    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        cnt2 += min(m[ch], mc[ch]);
    }

    cout << cnt << endl
         << cnt2 << endl;

    return 0;
}
