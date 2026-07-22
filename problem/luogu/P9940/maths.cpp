#include <bits/stdc++.h>
using namespace std;

map<int, int> pos;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string alphabet, heard;
    cin >> alphabet >> heard;

    for (int i = 0; i < 26; i++)
    {
        pos[alphabet[i] - 'a'] = i;
    }

    int answer = 1;
    for (int i = 1; i < (int)heard.size(); i++)
    {
        int last_pos = pos[heard[i - 1] - 'a'];
        int now_pos = pos[heard[i] - 'a'];

        if (now_pos <= last_pos)
        {
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}