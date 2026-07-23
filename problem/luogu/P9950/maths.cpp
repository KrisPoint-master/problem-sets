#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;

int n;
string A, B;

int main(int argc, char const *argv[])
{
    cin >> n;
    cin >> A >> B;
    int l = -1, r = -1;
    int cnt = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (l == -1 && A[i] != B[i])
        {
            l = i;
            r = i;
            continue;
        }
        if (A[i] == B[i])
        {
            if (l != -1 && r != -1)
            {
                cnt++;
            }
            l = r = -1;
            continue;
        }
        if (A[i] != B[i])
        {
            r++;
        }
    }

    cout << cnt << endl;

    return 0;
}
