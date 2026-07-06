#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    double sum = 1,l = 1;
    for (int i = 1; i <= t; i++)
    {   
        l *= i;
        sum += 1/l;
    }
    cout << fixed << setprecision(10) << sum << endl;
    
    return 0;
}
