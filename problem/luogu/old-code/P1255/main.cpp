#include<bits/stdc++.h>
using namespace std;

struct Bigint{
    string num;
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1, add = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x + y + add;
            ans.push_back('0' + result % 10);
            add = result / 10;
            i -= 1;
            j -= 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

Bigint a[5005];
int n;

int main(){
    cin >> n;
    for(int i = 0;i<n;i++){
        if(i % 2 == 0) a[i].num = "1";
        else a[i].num = "2";
    }
    for(int i = 2;i<n;i++){
        a[i].num = a[i].addStrings(a[i-1].num,a[i-2].num);
    }
    cout<< a[n-1].num << endl;
    return 0;
}

