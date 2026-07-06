#include <bits/stdc++.h>
using namespace std;
int a[27], maxn, minn = 101, dd;
char b[101];
bool prim_(int x)
{
	if (x == 0 || x == 1)
		return false;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}
int main()
{
	cin >> b;
	for (int i = 0; i < strlen(b); i++)
		a[b[i] - 'a' + 1]++;
	for (int i = 1; i <= 26; i++)
		if (a[i])
			maxn = max(maxn, a[i]), minn = min(minn, a[i]);
	dd = maxn - minn;
	if (prim_(dd))
	{
		cout << "Lucky Word" << endl
			 << dd;
	}
	else
		cout << "No Answer" << endl
			 << "0";
	return 0;
}