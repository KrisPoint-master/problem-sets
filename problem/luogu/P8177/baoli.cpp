#include <bits/stdc++.h>
using namespace std;

int T;

vector<int> num;

/*

    auto it = std::find(vec.begin(), vec.end(), target);
    if (it != vec.end()) {
        std::cout << "Found " << target << " at index " << std::distance(vec.begin(), it) << '\n';
    } else {
        std::cout << target << " not found in the vector.\n";
    }
*/

void work(int n, int a, int d)
{
    num.clear();
    for (int i = 0; i < n; i++)
    {
        num.push_back(a + i * d);
    }
    int cnt = 0;
    while (1)
    {
        int flag = 0;
        for (int i = 0; i < (int)num.size(); i++)
        {
            for (int j = i + 1; j < (int)num.size(); j++)
            {
                if ((num[i] + num[j]) & 1)
                    continue;
                int mid = (num[i] + num[j]) / 2;
                auto it = find(num.begin(), num.end(), mid);
                if (it != num.end())
                    continue;
                num.push_back(mid);
                cnt++;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
    cout << cnt << endl;
}

int main(int argc, char const *argv[])
{
    cin >> T;
    while (T--)
    {
        int n, a, d;
        cin >> n >> a >> d;
        work(n, a, d);
    }
    return 0;
}
