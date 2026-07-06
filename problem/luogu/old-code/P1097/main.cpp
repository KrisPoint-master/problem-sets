#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

set<long long> s;
map<long long,int> m;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        s.insert(a);    
        m[a]++;
    }

    for(auto iter : s){
        cout << iter << " " << m[iter] << endl;
    }
    
    return 0;
}
