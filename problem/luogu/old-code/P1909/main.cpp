#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a,b;
    int i;
    int money = 1145141919;
    for(i=1;i<=3;i++){
        cin >> a >> b;
        int shang = n / a;
        if( n % a != 0){
            shang++;
        }
        if( money > shang*b)
            money = shang*b;
    }
    cout << money << endl;
    return 0;
}