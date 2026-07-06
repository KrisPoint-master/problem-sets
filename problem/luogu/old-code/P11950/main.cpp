#include <bits/stdc++.h>
using namespace std;

struct student
{
    int id;
    int n;
    double ax_num;
    double grade[105];
    void sort_grade()
    {
        sort(grade + 1, grade + 1 + n);
    }
    void calc_a_num()
    {
        double sum = 0;
        // cout << id << " ";
        for (int i = 2; i <= n - 1; i++)
        {
            // cout << grade[i] << " ";
            sum += (double)grade[i];
        }
        sum /= (double)(n - 2);
        ax_num = sum;
        // cout << endl
        //  << sum << endl;
    }
} a[105];

bool sortcmp(student a, student b)
{
    if (a.ax_num == b.ax_num)
        return a.id < b.id;
    return a.ax_num > b.ax_num;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        a[i].id = i;
        a[i].n = m;
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i].grade[j];
        }
        a[i].sort_grade();
        a[i].calc_a_num();
    }
    sort(a + 1, a + 1 + n, sortcmp);

    for (int i = 1; i <= n; i++)
    {
        cout << a[i].id << " ";
    }

    return 0;
}
