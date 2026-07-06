#include <bits/stdc++.h>
using namespace std;


const int maxn = 1e6+5;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
long long a[maxn],b[maxn];
long long c[maxn];
int pc[maxn];
int n;

long long calc(int i,int j)
{
    return a[i] + b[j];
}
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    
    for (int i = 1; i <= n; i++)
    {
        pc[i]  = 1;
        c[i] = calc(i,1);
        pq.push(make_pair(c[i],i));
    }
    priority_queue<int,vector<int>,greater<int>> pq2;
    while(n--)
    {
        pair<int,int> minpq = pq.top();
        pq.pop();
        int k = minpq.second;
        c[k] = calc(k,++pc[k]);
        cout << minpq.first << " ";
        pq.push(make_pair(c[k],k));
    }

    
    return 0;
}
