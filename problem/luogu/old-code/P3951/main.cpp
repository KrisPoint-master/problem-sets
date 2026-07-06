#include <bits/stdc++.h>
using namespace std;

int a, b;
int pos[10000006];
int l;

int main(int argc, char const *argv[])
{
    cin >> a >> b;
    for (int i = 0; i <= a * b; i++)
    {
        for (int j = 0; j <= a * b; j++)
        {
            int index = i * a + b * j;
            pos[index] = 1;
            l = index;
        }
    }

    for (int i = a * b; i > 0; i--)
    {
        if (!pos[i])
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
