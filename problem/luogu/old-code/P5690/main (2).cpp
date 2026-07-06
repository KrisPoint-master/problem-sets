#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn];

int main(int argc, char **argv)
{
    int cnt = 0;
    char k = getchar();
    char l = getchar();
    int a = (k - '0') * 10 + (l - '0');
    getchar();
    k = getchar();
    l = getchar();
    int b = (k - '0') * 10 + (l - '0');

    if (b > 28 && a == 2)
        cnt++;
    if ((b > 30 && (a == 4 || a == 6 || a == 9 || a == 11)) || !((b == 30) && a > 12))
        cnt++;
    if ((b > 31 && !(a == 2 || a == 4 || a == 6 || a == 9 || a == 11)) || !((b == 31) && a > 12))
        cnt++;
    cout << cnt << endl;
    return 0;
}