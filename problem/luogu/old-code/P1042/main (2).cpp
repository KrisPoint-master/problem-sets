#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

char a[maxn];

int main(int argc, char **argv)
{
    int cnt = 0;
    bool stop_input_flag = 0;
    while (1)
    {
        if (stop_input_flag != 1)
        {
            char c;
            cin >> c;
            a[++cnt] = c;
            if (c == 'E')
                stop_input_flag = 1;
        }
        
    }
    return 0;
}