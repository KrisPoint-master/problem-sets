#include<bits/stdc++.h>
using namespace std;
bool isp(int n){
    for(int i = 2; i*i < n; ++i)
        if(n % i == 0)  return false;
    return true;
}
int main()
{
    for(int i = 6; i <= 100; i += 2)
    {
        for(int j = 2; j <= i/2; ++j)
        {
            if(isp(j) && isp(i-j))
            {
                cout << i << '=' << j << '+' << i - j << endl;
                break;
            }
        }
    }
    return 0;
}

