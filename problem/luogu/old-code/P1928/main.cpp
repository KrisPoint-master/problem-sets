#include<bits/stdc++.h>
using namespace std;
string UnPasswd(){
    int k;
    char c;
    string s="",str="";
    while(cin>>c){
        if(c=='['){
            cin>>k;
            str=UnPasswd();
            while(k--){
                s+=str;
            }
        }
        else if(c==']'){
            return s;
        }else{
            s+=c;
        }
    }
    return s;
}
int main(){
    cout << UnPasswd() << endl;
    return 0;
}
