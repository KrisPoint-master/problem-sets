#include <bits/stdc++.h>
using namespace std;

const long long max_n = 7;

long long num[10];

int main(long long argc, char const *argv[])
{
    for (long long i = 1; i <= max_n; i++)
    {
        cin >> num[i];
    }

    sort(num + 1, num + 1 + max_n);

    do
    {
        long long a = num[1];
        long long b = num[2];
        long long c = num[3];
        if (a + b == num[4])
        {
            if (b + c == num[5])
            {
                if (a + c == num[6])
                {
                    if (a + b + c == num[7])
                    {
                        long long max, min, mid;
                        vector<long long> t;
                        t.push_back(a);
                        t.push_back(b);
                        t.push_back(c);
                        sort(t.begin(), t.end());
                        for (auto iter : t)
                        {
                            cout << iter << " ";
                        }
                        return 0;
                    }
                }
            }
        }
    } while (next_permutation(num + 1, num + 1 + max_n));

    return 0;
}
