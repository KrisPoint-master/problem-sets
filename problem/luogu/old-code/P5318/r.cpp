#include <bits/stdc++.h>
using namespace std;

std::random_device rd;
std::default_random_engine __rnd(rd());

std::mt19937 mtrnd(rd());

//生成[l,r]之间的随机整数
int rnd(int l,int r) {
    return __rnd() % (r-l+1) + l;
}

int main(int argc, char const *argv[])
{
    int n,m;
    // cin >> n >> m;
    n = rnd(1,100);
    m = n-1;
    cout << n << " " << m << endl;
    for (int i = 1; i <= m; i++)
    {
        int u,v;
        // cin >> u >> v;
        u = rnd(1,m);
        v = rnd(1,m);
        cout << u << " " << v << endl;
    }
    
    return 0;
}
