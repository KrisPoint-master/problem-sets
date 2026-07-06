#include <bits/stdc++.h>
using namespace std;
int n;
char s[17];
long long s1, s2, s3, s4;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s[0] == 'M')
            s1++;
        if (s[0] == 'C')
            s2++;
        if (s[0] == 'O')
            s3++;
        if (s[0] == 'I')
            s4++;
    }

    cout << s1 * s4 * (s2 + s3) + s2 * s3 * (s1 + s4) << endl;

    return 0;
}