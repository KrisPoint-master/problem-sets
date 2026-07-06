#include <bits/stdc++.h>
using namespace std;

struct Bigint
{
    string num;
    string addStrings(string num1, string num2)
    {
        int i = num1.length() - 1, j = num2.length() - 1, add = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || add != 0)
        {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x + y + add;
            ans.push_back('0' + result % 10);
            add = result / 10;
            i -= 1;
            j -= 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
Bigint f[100000];

int main()
{
    long long n; // 10^5
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= i / 2; j++)
        {
            f[i].num = f[i].addStrings(f[j].num, f[i].num);
        }
        f[i].num = f[i].addStrings(f[i].num, "1");
    }
    cout << f[n].num << endl;
    return 0;
}
