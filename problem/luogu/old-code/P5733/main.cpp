#include <bits/stdc++.h>
using namespace std;

int n,m;
string a;

int main(int argc, char const *argv[])
{
    cin >> a;
    for (int i = 0; i <= a.length(); i++)
    {
        if(a[i] >= 'a' && a[i] <= 'z'){
            a[i] += 'A' - 'a';
        }
    }
    cout << a << endl;
    return 0;
}
