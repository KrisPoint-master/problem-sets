#include <bits/stdc++.h>
using namespace std;

const int max_n = 1e6 + 5;

struct datas
{
    int id;
    int flag;
    int data;
};

vector<datas> numbers(max_n);
vector<datas> numbers2(max_n);
int last = 1;

int n;

int check(vector<datas> &numbers)
{
    for (auto it : numbers)
    {
        if ((it.data != -1) && (it.id <= n) && (it.id >= 1))
        {
            return 1;
        }
    }
    return 0;
}

int pos = 0;

enum STATUS
{
    NUMBERS,
    NUMBERS2
};

int main(int argc, char const *argv[])
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        numbers[i].id = i;
        numbers2[i].id = i;
        numbers[i].data = i;
        numbers[i].flag = 1;
    }
    int vectorstatus = STATUS::NUMBERS;

    int day = 1;
    int day_flag = 0;
    while (check((vectorstatus) ? numbers2 : numbers))
    {
        if (vectorstatus)
        {
            // NUMBERS2 code
            for (int i = 1; i <= n; i += 3)
            {
                numbers2[i].flag = 0;
                if (i == n)
                    day_flag = day;
            }
            numbers.clear();
            numbers.push_back({0, 0, 0});
            for (auto it : numbers2)
            {
                numbers.push_back(it);
            }
        }
        else
        {
            // NUMBER code
            for (int i = 1; i <= n; i += 3)
            {
                numbers[i].flag = 0;
                if (i == n)
                    day_flag = day;
            }
            numbers2.clear();
            numbers2.push_back({0, 0});
            for (auto it : numbers)
            {
                numbers2.push_back(it);
            }
        }
        day++;
    }
    return 0;
}
