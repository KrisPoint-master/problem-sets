#include <bits/stdc++.h>
using namespace std;

struct item
{
    int p;
    int d;
}items[100005];

bool operator<(const item& a, const item& b) {
    return a.p < b.p; 
}

bool cmp(item a,item b)
{
    return a.d < b.d;
}


int main(int argc, char const *argv[])
{
    int n;
    while(cin >> n)
    {
        priority_queue<int,vector<int>,greater<int>> h;
        for(int i = 1;i <= n;i ++)
        {
            cin >> items[i].p >> items[i].d;
        }
        sort(items+1,items+1+n,cmp);
        for (int i = 1; i <= n; i++)
        {
            if(items[i].d > h.size())
            {
                h.push(items[i].p);
            }
            else if (!h.empty() && items[i].p > h.top()) {
                h.pop();
                h.push(items[i].p);
            }
        }
        long long ans = 0;
        while (!h.empty()) {
            ans += h.top();
            h.pop();
        }
        cout << ans << endl;
    }
    
    return 0;
}
