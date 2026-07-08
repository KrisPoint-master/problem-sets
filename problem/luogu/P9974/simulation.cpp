#include <bits/stdc++.h>
using namespace std;

const long long max_n = 3e5 + 5;

long long n, m;
long long height[max_n], candy_long[max_n];

int main(int argc, char const *argv[])
{
    // --- INPUT ---
    cin >> n >> m;
    for (long long i = 1; i <= n; i++)
        cin >> height[i];
    for (long long j = 1; j <= m; j++)
        cin >> candy_long[j];
    // --- INPUT END ---

    // ---WORK---

    void eat(long long now_candy);
    for (long long now_candy = 1; now_candy <= m; now_candy++)
    {
        eat(now_candy); // this is the candy's idx now
    }

    for (long long i = 1; i <= n; i++)
    {
        cout << height[i] << '\n';
    }

    // ---WORK END---

    return 0;
}

void eat(long long now_candy_id)
{
    // long long *simulation = new long long[max_n];
    long long now_candy_long = candy_long[now_candy_id];
    long long last_prev = 0;
    for (long long i = 1; i <= n && now_candy_long > 0; i++)
    {
        long long now_cow_height = height[i];
        if (last_prev >= now_cow_height) // cow height is low
            continue;
        long long sub = now_cow_height - last_prev;
        if (sub > now_candy_long)
        {
            last_prev = now_candy_long;
            now_cow_height += now_candy_long;
            height[i] += now_candy_long;
            now_candy_long = 0;
            continue;
        }
        last_prev = now_cow_height;
        now_cow_height += sub;
        height[i] += sub;
        now_candy_long -= sub;
    }
    // delete simulation;
}