#include<bits/stdc++.h>
using namespace std;

struct Oo{
    public:
    long long x,y;

    long long mj(long long x,long long y){
        return x*y;
    }

    void print(long long x,long long y){
        if(mj(this->x,this->y) > mj(x,y)){
            cout << "Alice" << endl;
        }else{
            cout << "Bob" << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    Oo a,b;
    cin >> a.x;
    a.y = a.x;
    cin >> b.x >> b.y;
    a.print(b.x,b.y);
    return 0;
}
