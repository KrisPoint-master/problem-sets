#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn];
int n;

vector<pair<int, int>> freeticket;
int ans;

int main(int argc, char **argv)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int id, price, time;
        cin >> id >> price >> time;
        if (id == 0)
        {
            ans += price;
            freeticket.push_back(make_pair(price, time));
            // cout << "HAS A FREE TICKET " << price << " " << time << endl;
        }
        if (id != 0)
        {
        label_1:
            if (freeticket.size())
            {
                bool flag = 0;
                for (auto k : freeticket)
                {
                    if (time - k.second <= 45 && k.first >= price)
                    {
                        // cout << "FREE TICK" << endl;
                        auto it = find(freeticket.begin(), freeticket.end(), k);
                        int index = distance(freeticket.begin(), it);
                        freeticket.erase(freeticket.begin() + index);
                        flag = 1;
                        break;
                    }
                }
                if (flag)
                    continue;
            }

            ans += price;
            // cout << "NO FREE" << endl;
        }
    }
    cout << ans << endl;

    return 0;
}