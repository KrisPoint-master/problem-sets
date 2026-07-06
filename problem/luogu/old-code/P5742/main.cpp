#include<iostream>

using namespace std;

struct Student{
	int num;
	int a;
	int b;
	float sum;
};

int main(){
	Student a[1005];
	int n;
	cin >> n;
	for(i
	nt i=0; i<n; i++){
		cin >> a[i].num >> a[i].a >> a[i].b;
		a[i].sum = a[i].a * 0.7 + a[i].b * 0.3;
	}
	for(int i=0; i<n; i++){
		if((a[i].a+a[i].b)>140 && a[i].sum>=80){
			cout << "Excellent" << endl;
		}
		else
			cout << "Not excellent" << endl;
	}
	return 0;
}

