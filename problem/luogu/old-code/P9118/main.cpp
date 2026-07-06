#include <bits/stdc++.h>
using namespace std;

int n,k;

map<int,pair<int,int>> m;

int main(int argc, char const *argv[])
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = k; j <= 100; j++)
        {
            int sum = pow(i,j);
            if(sum > n) break;
            m[sum] = {i,j};
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if(m[i].second == 0 && m[i].first == 0)
        {
            // 
        }   
        else
        {
            cnt ++;
        }
    }

    cout << cnt << endl;
    
    
    return 0;
}
