#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    long long a, b, l;
    char c;
    long long n;
    cin >> n;
    while (n--)
    {
        scanf("%d%c%d%c%d", &a, &c, &b, &c, &l);
        if (a + b == l)
        {
            cout << "Right!" << endl;
        }
        else
        {
            cout << "Wrong!" << endl;
        }
    }
    return 0;
}
