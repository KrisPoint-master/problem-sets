#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
template<typename T = int,int siz = maxn>
struct mystack{
    T sta[maxn];
    int head = 0;
    void clear() { head = 0;}
    void push(T a) { sta[head++] = a;}
    void pop(){head--;}
    T pop2(){ return sta[--head];}
    T top() { return sta[head-1];}
    bool empty() { return head == 0;}
};
mystack<int> s;
int num;


int main(){
    string str;
    cin >> str;
    for(int i = 0;i < str.size();i++){
        char c = str[i];
        if( c >= '0' && c <= '9')
        {
            num= num *10 + (c - '0');
            continue;
        }

        if( c == '.' ) {
            s.push(num);
            num = 0;
            continue;
        }

        int b = s.pop2(),a = s.pop2();
        switch(c){
            case '+':
                s.push(a+b);
            case '-':
                s.push(a-b);
            case '*':
                s.push(a*b);
            case '/':
                s.push(a/b);
        }
    }
    cout << s.top();
    return 0;
}
