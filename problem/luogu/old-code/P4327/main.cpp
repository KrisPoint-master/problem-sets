#include <bits/stdc++.h>
using namespace std;
char s[10086];
int main()
{
    cin >> s;
    int l = strlen(s), t = 1, x = 0;
    // 1
    cout << "..#";
    for (int i = 4; i <= 4 * l + 1; i++)
    {
        if (i % 4 == 3 && t == 0 || i % 4 == 3 && t == 1)
            cout << "#", t++;
        else if (i % 4 == 3 && t == 2)
            cout << "*", t = 0;
        else
            cout << ".";
    }
    cout << endl;
    // 2
    t = 1;
    for (int i = 1; i <= 4 * l + 1; i++)
    {
        if (i % 2 == 1)
            cout << ".";
        else if (i % 2 == 0)
        {
            if (t == 1 || t == 2 || t == 3 || t == 4)
                cout << "#", t++;
            else
                cout << "*", t++, t = t % 6;
        }
    }
    cout << endl;
    // 3
    t = 2;
    cout << "#";
    for (int i = 2; i <= 4 * l; i++)
    {
        if (i % 2 == 0)
            cout << ".";
        else if (i % 2 == 1)
        {
            if (t == 3)
                cout << "#", t++;
            else if (t == 1 || t == 5)
                cout << "*", t++;
            else
                cout << s[x], t++, x++;
            t %= 6;
        }
    }
    if (l % 3 == 0)
        cout << "*";
    else
        cout << "#";
    cout << endl;
    // 4
    t = 1;
    for (int i = 1; i <= 4 * l + 1; i++)
    {
        if (i % 2 == 1)
            cout << ".";
        else if (i % 2 == 0)
        {
            if (t == 1 || t == 2 || t == 3 || t == 4)
                cout << "#", t++;
            else
                cout << "*", t++, t = t % 6;
        }
    }
    cout << endl;

    t = 1;
    cout << "..#";
    for (int i = 4; i <= 4 * l + 1; i++)
    {
        if (i % 4 == 3 && t == 0 || i % 4 == 3 && t == 1)
            cout << "#", t++;
        else if (i % 4 == 3 && t == 2)
            cout << "*", t = 0;
        else
            cout << ".";
    }
    cout << endl;
    return 0;
}