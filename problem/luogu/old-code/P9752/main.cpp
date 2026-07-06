#include<bits/stdc++.h>
using namespace std;
int n;
int bi[1005];
int a[1005][1005],b[100],b2[100];

void chai(int n){
    for (int i = 5; i >= 1; i--)
    {
        b[i] = n % 10;
        n /= 10;
    }
}

bool check_1(int n){
    int temp = 0;
    int temp2 = 0;
    for (int i = 1; i <= 5; i++)
    {
       // 00001
       // 00010
       // NO
       if(a[n][i] == b[i]){
            temp ++;
       }
       if(temp > 1) return 0;
    }
    return 1;
}

bool check_2(int n){
    int sum = 0;
    for (int i =1; i <= 5; i++)
    {
        cout << b[i] << " " << a[n][i] << endl;;
        sum += abs(b[i]-a[n][i]);
    }
    // cout << sum << endl;
    return (sum == 2);
    
}

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i <= 99999; i++)
    {
        memset(bi,0,sizeof(bi));
        chai(i);
        for (int j = 1; j <= n; j++)
        {
            bi[j] = check_1(j);
            if(bi[i])
                bi[i] = check_2(j);

            cout << b[i] << " ";
        }
        
    }
   return 0;
}
