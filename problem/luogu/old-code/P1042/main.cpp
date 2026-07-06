#include <bits/stdc++.h>
using namespace std;

string a;
int w = 0, l = 0;

long long abs(long long n){
    return (n >= 0) ? n : -n;
}

int init()
{
    char c;
    bool v = 0;
    while (1)
    {
        cin >> c;
        if (c == 'E')
        {
            return 0;
        }
        a += c;
        v = 1;
    } 
    v = 0;
    if(!v) return 1;
}
void print(int a, int b)
{
    cout << a << ":" << b << endl;
}

void work(int k)
{

    for (int i = 0; i < a.size(); i++)
    {
        char c = a[i];
        if (c == 'W')
            w++;
        if (c == 'L')
            l++;
        // printf("W:%d L:%d\n", w, l);
        if (abs(w - l) >= 2 && abs(w + l) >= k)
        {
            print(w, l);
            w = 0, l = 0;
        }
    }
    if(w || l) print(w,l); 
    w = 0,l = 0;
    cout << endl;
}

int main(int argc, char const *argv[])
{
    if(!init()){
        print(0,0);
        cout << endl;
        print(0,0);
        return 0;
    }
    work(11);
    work(21);
    return 0;
}
