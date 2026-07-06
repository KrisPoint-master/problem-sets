#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+5;
int n,k;
int a[1000005];

void workk1()
{
    cout << n << endl;
    exit(0);
}

void workkdy2()
{
for (int i = 0; i <= 100; i++)
    {
        for (int j = k; j <= 100; j++)
        {
            long long sum = pow(i,j);
            if(sum < 1000000)
            {
                a[sum] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if(a[i]) cnt ++;
    }

    cout << cnt << endl;
    exit(0);
}

map<long long,int> ma;

//口决: 是1就乘,base增增
// long long
template<typename  T =long long>
T quick_pow(T base, T b) {
    T ans = 1;
    for(; b; b>>=1)
    {
        if(b & 1)
            ans = ans * base;
        base = base * base;
    }
    return ans;
}

set<long long> s;

int main(int argc, char const *argv[])
{
    cin >> n >> k;
    if(n <= 1e6 + 5) workkdy2();
    long long cnt = 0;

    for (int i = 1; i <= maxn - 5; i++)
    {
        for (int j = k; j <= 500; j++)
        {
            if(i == j) continue;
            long long sum = (long long)quick_pow((long long)i,(long long)j);
            if(sum > n) break;
            s.insert(sum);
        }   
    }
    
    cout << s.size() << endl;
    
    return 0;
}