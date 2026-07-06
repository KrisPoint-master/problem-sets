#include <bits/stdc++.h>
using namespace std;
int n,h,l,ans;
int main()
{
    cin >> n;
    int i = n;
    while(i --> 1){
        cin >> h;
        ans += (h > l) ? (h - l) : 0;  // if 高度<h[i] 最终高度 then 答案 + 最终高度 - 现在的高度
        l = h;                         // 高度 = 最终高度
    }
    cout << ans << endl;
    return 0;
}
