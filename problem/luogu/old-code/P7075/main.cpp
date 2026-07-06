#include <bits/stdc++.h>
using namespace std;

bool flag = 0;
int dayinmouth[13]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int sum_day[13]{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
int sum[7000];
void print(int years, int mouth, int day, int isBC = 0)
{
    if (!isBC)
        printf("%d %d %d\n", day, mouth, years);
    else
        printf("%d %d %d BC\n", day, mouth, years);
}

int yearmouthday(int y)
{
    if (y > 1582)
    {
        return ((y % 400 == 0) || ((y % 4 == 0) && !(y % 100 == 0))) ? 366 : 365;
    }
    return (y % 4 == 0) ? 366 : 365;
}

int mouthdays(int y, int m)
{
    if (yearmouthday(y) == 365)
    {
        return dayinmouth[m];
    }
    if (m == 2)
        return 366;

    return 365;
}

int nextyears(int thisyears)
{
    return (thisyears) ? thisyears + 1 : thisyears + 2;
}

void out(int a)
{
    if (a <= 365)
    {
        flag ^= 1;
        dayinmouth[2]++;
        int s = 0, mth;
        for (int i = 1; i <= 12; i++)
        {
            s += dayinmouth[i];
            if (s >= a)
            {
                mth = i;
                a -= (s - dayinmouth[i]);
                print(4713, mth, a + 1, 1);
                break;
            }
        }
        dayinmouth[2]--;
        flag ^= 1;
        return;
    }
    int years = -4713;
    int mouth = 1;
    int day = 1;
    for (int i = -4713; i < 1582; i = nextyears(i))
    {
        sum[i + 4713 + 1] += (sum[i + 4713] + yearmouthday(i));
        // cout << sum[i + 4713 + 1] << " ";
        // 6295
    }
    // cout << sum[4714];
    int *ans = lower_bound(sum + 1, sum + 1 + 4713, a);
    // distance(sum + 1, ans)
    // 0 365 365*2
    // 366 -> 1
    int thisyear = distance(sum + 1, ans);
    years += thisyear;
    int otherday = sum[thisyear + 1] - sum[thisyear];
    ans = lower_bound(sum_day, sum_day + 13, otherday);
    int thismouth = distance(sum_day + 1, ans);
    thismouth = (thismouth + 1) % 12;
    int thisday = mouthdays(thisyear, thismouth);
    thisday -= sum_day[thismouth];
    otherday -= sum_day[thismouth];
    cout << years << " " << thismouth << " " << thisday << endl;
}

int main(int argc, char const *argv[])
{
    int Q;
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        int tmp;
        cin >> tmp;
        out(tmp);
        // cout << yearmouthday(tmp);
    }

    return 0;
}
