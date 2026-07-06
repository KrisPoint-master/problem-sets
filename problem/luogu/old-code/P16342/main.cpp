#include <bits/stdc++.h>
using namespace std;

void work(long long a, long long b);
int main()
{
    long long a, b;
    cin >> a >> b;
    if (a % b == 0)
        goto end;
    work(a, b);
    return 0;
end:
    cout << 0 << endl;
    return 0;
}

void work(long long a, long long b)
{
    int magic_num = 500;
    if (a < 4000 && b < 4000)
    {
        magic_num = 1;
    }
    long long min_val = INT32_MAX;
    for (long long i = -b / magic_num; i <= b / magic_num; i++)
    {
        // for i --> b
        long long t1 = a + i;
        if (t1 < 0)
            continue;
        for (long long j = -b / magic_num; j <= b / magic_num; j++)
        {
            // for j --> b
            long long t2 = b + j;
            if (t1 < t2)
                break;
            if (t2 <= 0)
                continue;
            if (t1 % t2 == 0)
            {
                // cout << abs(i) + abs(j) << endl;
                min_val = min(min_val, static_cast<long long>(abs(i) + abs(j)));
                if (min_val == 0)
                    return;
            }
        }
    }
    cout << min_val << endl;
}