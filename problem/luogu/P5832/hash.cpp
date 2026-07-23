#include <bits/stdc++.h>
using namespace std;

constexpr int B = 233;

using ll = long long;

unsigned long long get_hash(const string &s)
{
    unsigned long long res = 0;
    for (size_t i = 0; i < s.size(); ++i)
    {
        res = ((ll)res * B + s[i]);
    }
    return res;
}

bool cmp(const string &s, const string &t)
{
    return get_hash(s) == get_hash(t);
}

#define jmp goto

int main(int argc, char const *argv[])
{
    int n;
    string s;
    cin >> n >> s;

    for (int k = 1; k <= n; ++k)
    {
        bool ok = true;
        for (int i = 0; i <= n - k; ++i)
        {
            string sub = s.substr(i, k);
            for (int j = i + 1; j <= n - k; ++j)
            {
                string sub2 = s.substr(j, k);
                if (cmp(sub, sub2))
                {
                    ok = false;
                    jmp end;
                }
            }
        }
    end:
        if (ok)
        {
            cout << k << endl;
            break;
        }
    }

    return 0;
}
