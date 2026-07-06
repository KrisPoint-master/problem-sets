#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+5;
int n,m;
struct candy
{
    int x,y;
    int sum(){return x+y;}
}c[maxn];

bool cmp(candy a,candy b)
{
    return a.sum() < b.sum(); 
}
bool cmp2(candy a,candy b)
{
    return a.x < b.x; 
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i].x >> c[i].y;
    }
    sort(c+1,c+1+n,cmp);
    // int cnt = 2;
    // m -= (c[1].sum());
    int cnt = m/(c[1].sum());
    m -= cnt * c[1].sum();
    cnt *= 2;
    sort(c+1,c+1+n,cmp2);
    for (int i = 2; i <= n; i++)
    {
        if(m < c[i].x)
        {
            break;
        }
        else
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
