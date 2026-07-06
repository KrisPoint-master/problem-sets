#include<bits/stdc++.h>

using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	if(a<=5&&b>=5) cout<<5<<endl;
	if(a<=7&&b>=7) cout<<7<<endl;
	if(a<=11&&b>=11) cout<<11<<endl;
	for(int d1=1;d1<=9;d1+=2)
		for(int d2=0;d2<=9;d2++){
			int num=d1*100+d2*10+d1; 
			if(num<a) continue;
			if(num>b) return 0; 
		
			int flag=1;
			for(int j=3;j*j<=num;j++){
				if(num%j==0){
					flag=0;
					break;
				}
			}
			if(flag) cout<<num<<endl;
	}
	for(int d1=1;d1<=9;d1+=2){
		for(int d2=0;d2<=9;d2++){
			for(int d3=0;d3<=9;d3++){
				int num=d1*10000+d2*1000+d3*100+d2*10+d1;
				if(num<a) continue;
				if(num>b) break;
				int flag=1;
				for(int j=3;j*j<=num;j++){
					if(num%j==0){
						flag=0;
						break;
					}
				}
				if(flag) cout<<num<<endl;
			}
		}
	} 
	
	
	for(int d1=1;d1<=9;d1+=2)
		for(int d2=0;d2<=9;d2++)
			for(int d3=0;d3<=9;d3++)
				for(int d4=0;d4<=9;d4++){
					int num=d1*1000000+d2*100000+d3*10000+d4*1000+d3*100+d2*10+d1;
					if(num<a) continue;
					if(num>b) break;
					int flag=1;
					for(int j=3;j*j<=num;j++){
						if(num%j==0){
							flag=0;
							break;
						}
					}
					if(flag) cout<<num<<endl;
				}
	return 0;	
}

