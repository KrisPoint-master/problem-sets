#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    long long n = 0,m = 0,a = 0,b = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {   
        for (int j = 0; j < m; j++)
        {
            if (i == j) a += (n - i) * (m - j);
            else b += (n - i) * (m - j);
        }
    }
    cout << a <<" " << b;
    
    return 0;
}
