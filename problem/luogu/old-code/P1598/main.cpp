#include <bits/stdc++.h>
using namespace std;
char c;
int t[114514], maxx;
int main()
{
    while (cin >> c)
        if(c >= 'A' || c <= 'Z')
            t[c - 'A']++;
    for (int i = 0; i <= 25; i++)
        if (t[i] > maxx)
            maxx = t[i];
    for (int i = maxx; i >= 1; i--)
    {
        for (int j = 0; j <= 25; j++)
            if (t[j] == i)
                cout << "* ", t[j]--;
            else
                cout << "  ";
        cout << endl;
    }
    for (int i = 0; i < 26; i++)
        cout << (char)(i + 'A') << " ";
    return 0;
}
