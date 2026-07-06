#include <bits/stdc++.h>
using namespace std;

string s;
double sum;

int main(void)
{
    cin >> s;

    vector<int> ve;

    int k = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] - '0') >= 0 && (s[i] - '0') <= 9)
        {
            ve.push_back(s[i] - '0');
            k ++;
        }
        else break;
    }

    int num = 0;
    for (int i = 0; i < k; i++)
    {
        num = (num + ve[i]) * 10;
    }
    num /= 10;

    if (s[k] == 'B')
    {
        for (int i = k + 2; i < s.size(); i++)
        {
            if (s[i] == 'B')
            {
                sum = num;
                break;
            }
            else if (s[i] == 'K')
            {
                sum = num / pow(2, 10);
                break;
            }
            else if (s[i] == 'M')
            {
                sum = num / pow(2, 20);
                break;
            }
            else if (s[i] == 'G')
            {
                sum = num / pow(2, 30);
                break;
            }
        }
    }
    if (s[k] == 'K')
    {
        for (int i = k + 2; i < s.size(); i++)
        {
            if (s[i] == 'B')
            {
                sum = num * pow(2, 10);
                break;
            }
            else if (s[i] == 'K')
            {
                sum = num;
                break;
            }
            else if (s[i] == 'M')
            {
                sum = num / pow(2, 10);
                break;
            }
            else if (s[i] == 'G')
            {
                sum = num / pow(2, 20);
                break;
            }
        }
    }
    if (s[k] == 'M')
    {
        for (int i = k + 2; i < s.size(); i++)
        {
            if (s[i] == 'B')
            {
                sum = num * pow(2, 20);
                break;
            }
            else if (s[i] == 'K')
            {
                sum = num * pow(2, 10);
                break;
            }
            else if (s[i] == 'M')
            {
                sum = num;
                break;
            }
            else if (s[i] == 'G')
            {
                sum = num / pow(2, 10);
                break;
            }
        }
    }
    if (s[k] == 'G')
    {
        for (int i = k + 2; i < s.size(); i++)
        {
            if (s[i] == 'B')
            {
                sum = num * pow(2, 30);
                break;
            }
            else if (s[i] == 'K')
            {
                sum = num * pow(2, 20);
                break;
            }
            else if (s[i] == 'M')
            {
                sum = num * pow(2, 10);
                break;
            }
            else if (s[i] == 'G')
            {
                sum = num;
                break;
            }
        }
    }

    cout << setiosflags(ios::fixed) << setprecision(6);
    cout << sum;

    return 0;
}
