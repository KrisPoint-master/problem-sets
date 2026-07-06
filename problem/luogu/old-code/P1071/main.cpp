#include <bits/stdc++.h>
using namespace std;

int e(){
    cout << "Failed" << endl;
    return 0;
}

int main(int argc, char const *argv[])
{
    int cnt = 0;
    string t;
    string a,b,c,ans; // 原信息,加密信息,要求小 C 翻译的加密信息
    map<char,char> m; // key : 加密char
    cin >> b >> a >> c;
    if(b.size() != a.size() || a.size() < 26) return e();

    for (int i = 0; i < a.size(); i++)
    {
        // init data
        if(!m.count(b[i]))
            m[b[i]] = a[i],cnt++;
        else if(m[b[i]] == a[i])
            continue;
        else
            return e(); 
    }
    
    if(cnt < 26) return e();
    cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        char c = m[b[i]];
        cnt = 0;
        for (int j = 0; j < 26; j++)
        {
            // cout << c << " " << m[b[j]] << endl;
            if(c == m[b[j]]) {
                cnt ++;
                if(cnt > 1) return e();
            }
        }
        cnt = 0;
    }
    for (int i = 0; i < c.size(); i++)
    {
        if(m[c[i]] == 0) return e();
        ans += m[c[i]];
    }
    cout << ans << endl;
    return 0;
}
/*
QWERTYUIOPLKJHGFDSAZXCVBNM
QWERTYUIOPLKJHGFDSAZXCVBNN
HIJACK
*/