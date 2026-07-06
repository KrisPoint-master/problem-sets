#include<bits/stdc++.h>
using namespace std;
struct stdstack{
    char sta[100000];
    int top = 0;

    void push(char s){
        sta[top++] = s;
    }

    char pop(){
        return sta[--top];
    }
    int isnull(){
        return top==0;
    }
};

int main(){
    char c;
    stdstack s;
    while(1){
        cin >> c;
        if(c == '@') break;
        if(c == '(') s.push(c);
        else if(c == ')') s.pop();
    }
    if(s.isnull()) cout << "YES";
    else cout << "NO";
    return 0;
}
