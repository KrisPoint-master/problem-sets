#include <bits/stdc++.h>
using namespace std;
int hour1, min1, sec1, hour2, min2, sec2;
int time1, time2;
int num;
long long n;
int main()
{
    scanf("%d:%d:%d", &hour1, &min1, &sec1);
    scanf("%d:%d:%d", &hour2, &min2, &sec2);
    scanf("%d",&num);
    time1 = hour1 * 3600 + min1 * 60 + sec1;
    time2 = hour2 * 3600 + min2 * 60 + sec2;
    n = (long long)num * (time2 - time1);
    cout << n;
    return 0;
}