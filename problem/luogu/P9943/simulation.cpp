#include <bits/stdc++.h>
using namespace std;

enum YEARS
{
    Ox = 0,
    Tiger,
    Rabbit,
    Dragon,
    Snake,
    Horse,
    Goat,
    Monkey,
    Rooster,
    Dog,
    Pig,
    Rat
};

map<string, int> animal_map = {
    {"Ox", Ox}, {"Tiger", Tiger}, {"Rabbit", Rabbit}, {"Dragon", Dragon}, {"Snake", Snake}, {"Horse", Horse}, {"Goat", Goat}, {"Monkey", Monkey}, {"Rooster", Rooster}, {"Dog", Dog}, {"Pig", Pig}, {"Rat", Rat}};

int get_last_animal_year_diff(int my_cn_zod, int his_cn_zod)
{
    int cnt = 0;
    int head = his_cn_zod;
    while (1)
    {
        head = (head - 1 + 12) % 12;
        cnt++;
        if (head == my_cn_zod)
            break;
    }
    return cnt;
}

int get_next_animal_year_diff(int my_cn_zod, int his_cn_zod)
{
    int cnt = 0;
    int head = his_cn_zod;
    while (1)
    {
        head = (head + 1) % 12;
        cnt++;
        if (head == my_cn_zod)
            break;
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;

    map<string, pair<int, int>> cow;
    cow["Bessie"] = {0, Ox};

    string w[9];
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 8; j++)
            cin >> w[j];

        string X = w[1];
        string type = w[4];
        int a = animal_map[w[5]];
        string Y = w[8];

        int y_a = cow[Y].second;
        int y_off = cow[Y].first;

        int diff;
        if (type == "previous")
            diff = get_last_animal_year_diff(a, y_a);
        else
            diff = get_next_animal_year_diff(a, y_a);

        if (type == "previous")
            cow[X] = {y_off - diff, a};
        else
            cow[X] = {y_off + diff, a};

        if (X == "Elsie")
            ans = abs(cow[X].first);
    }

    cout << ans << '\n';
    return 0;
}
