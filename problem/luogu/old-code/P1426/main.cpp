#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int s,x;
    cin >> s >> x;
    double a = 0,v = 7;
    while(a < s-x){
        v *= 0.98;
        a += v;
    }
    v *= 0.98;
    if(a+v > s+x){
        cout << 'n';
        return 0;
    }
    cout << 'y';
    return 0;
}