#include <bits/stdc++.h>
using namespace std;

long long n, k;
vector<string> vprev;
vector<string> vnext;
int work(long long n, long long k);
int main(long long argc, char const *argv[])
{
    work(1, 1);
    return 0;
}

int work(long long n, long long k)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;

    auto prevp = &vprev;
    auto nextp = &vnext;
    prevp->push_back("0");
    prevp->push_back("1");
    long long prevflag = 0; // prevp = &vprev
    long long nextflag = 1; // nextp = &vnext
    for (long long i = 2; i <= n; i++)
    {
        for (auto iter : *prevp)
        {
            string t = "0";
            t += iter;
            nextp->push_back(t);
        }
        reverse(prevp->begin(), prevp->end());
        for (auto iter : *prevp)
        {
            string t = "1";
            t += iter;
            nextp->push_back(t);
        }
        prevp->clear();
        prevflag ^= 1;
        nextflag ^= 1;
        prevp = (prevflag) ? &vnext : &vprev;
        nextp = (nextflag) ? &vnext : &vprev;
        if (i == k)
            break;
    }
    prevflag ^= 1;
    nextflag ^= 1;

    if (prevflag)
    {
        cout << vprev[k];
        // for (auto p : vprev)
        // {
        //     cout << p << " ";
        // }
        // cout << endl;
    }
    if (nextflag)
    {
        cout << vnext[k];
        // for (auto p : vnext)
        // {
        //     cout << p << " ";
        // }
        // cout << endl;
    }
    return 0;
}
