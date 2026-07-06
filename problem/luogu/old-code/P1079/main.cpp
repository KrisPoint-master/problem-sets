#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
char a[MAXN],key[101];

int main() {
	cin>>key;
	cin>>a;
	int len1=strlen(key);
	for(int i=0;i<len1;++i) {
		if(key[i]<='z'&&key[i]>='a') {
			key[i]=key[i]-'a'+'A';
		}
	}
	int len2=strlen(a);
	int sum=0;
	int zz=0;
	while(sum<len2) {
		if(zz==len1) zz=0;
		int bh=key[zz++]-'A';
		if(a[sum]<='z'&&a[sum]>='a') {
			if(a[sum]-'a'<bh) {
				bh-=a[sum]-'a'+1;
				a[sum]='z';
			}
			a[sum]-=bh;
		}
		if(a[sum]<='Z'&&a[sum]>='A') {
			if(a[sum]-'A'<bh) {
				bh-=a[sum]-'A'+1;
				a[sum]='Z';
			}
			a[sum]-=bh;
		}
		sum++;
	}
	cout<<a;
	return 0;
}