#include <bits/stdc++.h>
using namespace std;

int a[1000005];
int b[1000005];

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        b[t]++;
    }
    int cnt = 0;
    for (int i = 1; i <= 100005; i++)
    {
        if(b[i] > 0)
            cnt ++;
    }
    cout << cnt << endl;
    for (int i = 1; i <= 100005; i++)
    {
        if(b[i] > 0){
            cout << i << " ";
        }
    }
    cout << endl;    
    return 0;
}
