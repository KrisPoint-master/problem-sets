#include <bits/stdc++.h>
using namespace std;

template<typename T = int,int siz = 10086>
struct myqueue{
    T a[siz+5];
    //tail 指向最后一个元素后面一个位置
    //head 指向第一个元素
    int head = 0,tail=0; 

    void clear() { head =tail = 0;}

    void push(T b) { a[tail++] = b;}

    void pop(){head++;}
    void pop_back(){tail--;}

    T front() { return a[head];}
    T back() { return a[tail-1];}

    bool empty() { return head == tail;}

    int size() { return tail-head;}
};

int main(int argc, char const *argv[])
{
    int n,m,t = 1;
    cin >> n >> m;
    myqueue<int,1000005> a;
    for (int i = 1; i <= n; i++)
        a.push(i);

    while(a.size() != 0){
        if(t == m){
            cout << a.front() << " ";
            a.pop();
            t = 1;
        }else{
            t++;
            a.push(a.front());
            a.pop();
        }
    }
    
    return 0;
}
