//若之
#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
string name[maxn], s1, s2;
int a[maxn], n, b, c, d, sum;
int main()
{
    cin >> n;
    int i;
    for (i = 1; i <= n; i++)
    {
        cin >> name[i] >> b >> c >> s1 >> s2 >> d;
        if (b > 80 && d >= 1)
            a[i] += 8000;
        if (b > 85 && c > 80)
            a[i] += 4000;
        if (b > 90)
            a[i] += 2000;
        if (b > 85 && s2[0] == 'Y')
            a[i] += 1000;
        if (c > 80 && s1[0] == 'Y')
            a[i] += 850;
        sum += a[i];
    }
    string stu;
    int maxa = 0;
    for (i = 1; i <= n; i++)
    {
        if (a[i] > maxa)
        {
            maxa = a[i];
            stu = name[i];
        }
    }
    cout << stu << endl
         << maxa << endl
         << sum << endl;
    return 0;
}