#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1e7 + 20;

int m[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct qaq
{
    int Y, M, D;
} rem[MAXN], rem_400[400 * 366];
int tot = -1, tot_400 = -1;

void pre()
{
    for (int Y = -4712, M = 1, D = 1; Y < 1600; ++D)
    {
        int check = -1;
        if (Y <= 1582) /*<<- */
            check = (int)((-Y) % 4 == 0);
        else
            check = (int)(Y % 400 == 0 || (Y % 4 == 0 && Y % 100 != 0));

        if (D > m[M - 1] + (int)(M == 2) * check)
        {
            D = 1, ++M;
            if (M > 12)
                M = 1, ++Y;
        }

        if (Y == 1582 && M == 10 && D == 5)
            D = 15;

        ++tot;
        rem[tot].Y = Y, rem[tot].M = M, rem[tot].D = D;
    }
}

void pre2()
{
    for (int Y = 0, M = 1, D = 1; Y < 400; ++D)
    {
        if (D > m[M - 1] + (int)(M == 2) * (int)(Y == 0 || (Y % 4 == 0 && Y % 100 != 0)))
        {
            D = 1, ++M;
            if (M > 12)
                M = 1, ++Y;
        }

        ++tot_400;
        rem_400[tot_400].Y = Y, rem_400[tot_400].M = M, rem_400[tot_400].D = D;
    }
}

void put_ans(const int &Y, const int &M, const int &D)
{
    cout << D << " " << M << " ";
    if (Y <= 0)
        cout << -Y + 1 << " " << "BC";
    else
        cout << Y;

    cout << endl;
}

int main()
{
    pre();
    pre2();
    int T, r;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cin >> r;
        if (r <= tot)
            put_ans(rem[r].Y, rem[r].M, rem[r].D);
        else
        {
            r -= tot;
            int Y = 1600;
            if (r >= 365 * 400 + 100 - 3)
            {
                Y += (r / (365 * 400 + 100 - 3)) * 400;
                r %= 365 * 400 + 100 - 3;
            }
            put_ans(Y + rem_400[r].Y, rem_400[r].M, rem_400[r].D);
        }
    }
}
