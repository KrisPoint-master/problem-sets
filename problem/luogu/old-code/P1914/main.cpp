// askmb
#include<bits/stdc++.h>
using namespace std;

string s;
int n;
int main(int argc, char const *argv[])
{
    cin >> n >> s;
    for(int i = 0;i<n;i++){
        for(int i = 0;i<s.size();i++){
            s[i]++;
            if(s[i] > 'z'){
                s[i] = 'a';
            }
        }
    }
    cout << s;
    return 0;
}
