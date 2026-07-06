#include<bits/stdc++.h>
using namespace std;

long long n,m,ans;
const int mod = 100003;

int main(int argc, char const *argv[])
{
    cin >> m >> n;
    ans = pow(m,n) - m * pow(m - 1,n - 1);
    cout << ans << endl;
    return 0;
}
