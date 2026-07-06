#include<iostream> 
using namespace std;
long long n,a,b;
int main()
{
    cin>>a>>b>>n;  
    cout<<(a+(n-1)*(b-a)+a)*n/2; 
    return 0; 
}
