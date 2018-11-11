#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int n,a,b,t;
	cin>>n;
	while(n--){
		cin>>a>>b;
		if(a==b || b==a-2){
			t=a+b;
			if(a%2==0 && b%2==0)
			cout<<t<<endl;
			else cout<<t-1<<endl;
		}
		else{
			cout<<"No Number"<<endl;
		}
	}
}
