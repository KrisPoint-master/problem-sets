#include <bits/stdc++.h>
using namespace std;

string S;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> S;
        if (S[S.length() - 1] == '0')
        {
            cout << 'E' << endl;
        }
        else
        {
            cout << 'B' << endl;
        }
    }
    return 0;
}
