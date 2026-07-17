#include <bits/stdc++.h>
using namespace std;

const int max_n = 1e6 + 5;

int n, t;
int d[max_n], b[max_n];

int main(int argc, char const *argv[])
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i] >> b[i];
    }

    int cnt_eat = 0;
    int now_cnt = 0;
    int idx_d = 1;

    for (int i = 1; i <= t; i++) // i is day
    {
        if (d[idx_d] == i)
        {
            now_cnt += b[idx_d];
            idx_d++;
        }
        if (now_cnt >= 1)
        {
            cnt_eat++;
            now_cnt--;
        }
    }

    cout << cnt_eat << endl;

    return 0;
}
