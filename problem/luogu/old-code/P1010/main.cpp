#include<bits/stdc++.h>
using namespace std;

void dfs(int n){
 	if(n==1){
		cout<<"2(0)";
 	}else if(n==2){
 		cout<<"2";	
 	}else if(n==4){
 		cout<<"2(2)";
 	}else{
		int a;
		while(1){
			if(n==0){
				break;
			}else if(n==1||n==2||n==4){
				dfs(n);
				break;
			}else{
				a = floor(log(n)/log(2));

				if(a==1){
					cout<<"2";
				}else{
					cout<<"2(";
				    dfs(a);
				    cout<<")";
				}
				if(n-pow(2,a)){cout<<"+";}	
			}
			n = n-pow(2,a);						
		}
	}
}

int main(){
	int n;
	cin>>n;
	dfs(n);
	return 0;
}
