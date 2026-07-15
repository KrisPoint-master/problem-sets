#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    void work();
    int T;
    cin >> T;
    while (T--)
    {
        work();
    }
    return 0;
}

void work();

void work()
{
    long long n;
    cin >> n;
    long long get_ans(long long);
    long long ans = get_ans(n);
    cout << ans << endl;
}

inline long long get_query_cnt(long long l, long long r)
{
    return r - l + 1;
}

long long get_ans(long long x)
{
    if (x <= 44) return 0;

    // P=2
    if (45 <= x && x <= 49)
        return get_query_cnt(45, x);
    if (50 <= x && x <= 444)
        return get_query_cnt(45, 49);

    // P=3
    if (445 <= x && x <= 499)
        return get_query_cnt(445, x) + get_query_cnt(45, 49);
    if (500 <= x && x <= 4444)
        return get_query_cnt(445, 499) + get_query_cnt(45, 49);

    // P=4
    if (4445 <= x && x <= 4999)
        return get_query_cnt(4445, x) + get_query_cnt(445, 499) + get_query_cnt(45, 49);
    if (5000 <= x && x <= 44444)
        return get_query_cnt(4445, 4999) + get_query_cnt(445, 499) + get_query_cnt(45, 49);

    // P=5
    if (44445 <= x && x <= 49999)
        return get_query_cnt(44445, x) + get_query_cnt(4445, 4999) + get_query_cnt(445, 499) + get_query_cnt(45, 49);
    if (50000 <= x && x <= 444444)
        return get_query_cnt(44445, 49999) + get_query_cnt(4445, 4999) + get_query_cnt(445, 499) + get_query_cnt(45, 49);

    // P=6
    if (444445 <= x && x <= 499999)
        return get_query_cnt(444445, x) + get_query_cnt(44445, 49999) + get_query_cnt(4445, 4999) + get_query_cnt(445, 499) + get_query_cnt(45, 49);
    if (500000 <= x && x <= 4444444)
        return get_query_cnt(444445, 499999) + get_query_cnt(44445, 49999) + get_query_cnt(4445, 4999) + get_query_cnt(445, 499) + get_query_cnt(45, 49);

    // P=7
    if (4444445 <= x && x <= 4999999)
        return get_query_cnt(4444445, x) + get_query_cnt(444445, 499999) + get_query_cnt(44445, 49999) + get_query_cnt(4445, 4999) + get_query_cnt(445, 499) + get_query_cnt(45, 49);
    if (5000000 <= x && x <= 44444444)
        return get_query_cnt(4444445, 4999999) + get_query_cnt(444445, 499999) + get_query_cnt(44445, 49999) + get_query_cnt(4445, 4999) + get_query_cnt(445, 499) + get_query_cnt(45, 49);

    // P=8
    if (44444445 <= x && x <= 49999999)
        return get_query_cnt(44444445, x) + get_query_cnt(4444445, 4999999) + get_query_cnt(444445, 499999) + get_query_cnt(44445, 49999) + get_query_cnt(4445, 4999) + get_query_cnt(445, 499) + get_query_cnt(45, 49);
    if (50000000 <= x && x <= 444444444)
        return get_query_cnt(44444445, 49999999) + get_query_cnt(4444445, 4999999) + get_query_cnt(444445, 499999) + get_query_cnt(44445, 49999) + get_query_cnt(4445, 4999) + get_query_cnt(445, 499) + get_query_cnt(45, 49);

    // P=9
    if (444444445 <= x && x <= 499999999)
        return get_query_cnt(444444445, x) + get_query_cnt(44444445, 49999999) + get_query_cnt(4444445, 4999999) + get_query_cnt(444445, 499999) + get_query_cnt(44445, 49999) + get_query_cnt(4445, 4999) + get_query_cnt(445, 499) + get_query_cnt(45, 49);
    if (500000000 <= x && x <= 4444444444LL)
        return get_query_cnt(444444445, 499999999) + get_query_cnt(44444445, 49999999) + get_query_cnt(4444445, 4999999) + get_query_cnt(444445, 499999) + get_query_cnt(44445, 49999) + get_query_cnt(4445, 4999) + get_query_cnt(445, 499) + get_query_cnt(45, 49);

    // P=10
    if (4444444445LL <= x && x <= 4999999999LL)
        return get_query_cnt(4444444445LL, x) + get_query_cnt(444444445, 499999999) + get_query_cnt(44444445, 49999999) + get_query_cnt(4444445, 4999999) + get_query_cnt(444445, 499999) + get_query_cnt(44445, 49999) + get_query_cnt(4445, 4999) + get_query_cnt(445, 499) + get_query_cnt(45, 49);
    if (5000000000LL <= x)
        return get_query_cnt(4444444445LL, 4999999999LL) + get_query_cnt(444444445, 499999999) + get_query_cnt(44444445, 49999999) + get_query_cnt(4444445, 4999999) + get_query_cnt(444445, 499999) + get_query_cnt(44445, 49999) + get_query_cnt(4445, 4999) + get_query_cnt(445, 499) + get_query_cnt(45, 49);

    return 0;
}
