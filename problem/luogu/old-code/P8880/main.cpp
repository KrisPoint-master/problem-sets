#include<bits/stdc++.h>
using namespace std;
int n,c[100010];
int main()
{
	cin >> n;
	if(n%2==0)
	{
		cout<<-1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin >> c[i];
		if(c[i]%2==1) c[i]+=n;
	}
	for(int i=1;i<=n;i++) cout << c[i]/2 << " ";
	cout << endl;
	for(int i=1;i<=n;i++) cout << c[i]/2 << " ";
    return 0;
}