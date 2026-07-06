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

int main(int argc, char const *argv[])
{
    cin >> n >> k;
    if(k == 1) workk1();
    if(n <= 1e6 + 5) workkdy2();
    long long cnt = 0;
    for (int i = 1; i <= 100000; i++)
    {
        for (int j = k; j <= 1000; j++)
        {
            long long sum = static_cast<long long>(pow(i,j));
            if( sum <= n)
            {
                if(ma[sum] == 1)
                    continue;
                ma[sum] ++;
                cnt ++;
                for (int l = 2; l <= 10; l++)
                {
                    long long sum = static_cast<long long>(pow(i, j * l));
                    if(ma[sum] == 1)
                        continue;
                    ma[sum] ++;
                    cnt ++;
                }
            }
            else
            {
                break;
            }
        }
    }
    
    
    
    return 0;
}
