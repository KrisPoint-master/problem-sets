#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

struct student
{
    int id;
    int chinese;
    int math;
    int english;
} s[maxn];

long long tot_stu_f(student s)
{
    return s.chinese + s.math + s.english;
}
bool cmp(const student a, const student b)
{
    if (tot_stu_f(a) == tot_stu_f(b))
    {
        if (a.chinese == b.chinese)
            return a.id < b.id;
        else
            return a.chinese > b.chinese;
    }
    return tot_stu_f(a) > tot_stu_f(b);
}

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i].chinese >> s[i].math >> s[i].english;
        s[i].id = i;
    }

    sort(s + 1, s + n + 1, cmp);

    for (int i = 1; i <= 5; i++)
    {
        cout << s[i].id << " " << tot_stu_f(s[i]) << endl;
    }

    return 0;
}