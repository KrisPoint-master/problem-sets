#include<bits/stdc++.h>
using namespace std;
char a[1000];
char b[1000];
int f[1000][1000];

int main(int argc, char const *argv[])
{
    cin >> a >> b;
    int la = strlen(a);
    int lb = strlen(b);

    for(int i = 0;i<la;i++){
        for(int j = 0;j<lb;j++){
            if(a[i] == a[j]) f[i][j] = f[i-1][j-1];
            else f[i][j]=min(min(f[i-1][j],f[i][j-1]),f[i-1][j-1])+1;
        }
    }
    cout << f[la-1][lb-1];
    return 0;
}

