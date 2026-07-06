#include<bits/stdc++.h>
using namespace std;

string a,b;
int ans = 1,ans2 = 1;
int main(){
    cin >> a >> b;
    for(int i = 0;i<a.size();i++){
        ans *= a[i] - '@';
    }
    for(int i = 0;i<b.size();i++){
        ans2 *= b[i] - '@';
    }
    if(ans%47 == ans2%47){
        cout << "GO";
        return 0;
    }
    cout << "STAY";
    return 0;
}
