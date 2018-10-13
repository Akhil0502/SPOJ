#include <bits/stdc++.h>
using namespace std;
int util(int n){
	int b=0;
	while(true){
		if(n<=0) break;
		if(n%3 == 0 && b!=0) return n;
		n-=5;
		b+=5;
	}
	return -1;
}
int main() {
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		cout<<"Case "<<i+1<<": "<<util(n)<<endl;
	}
	return 0;
} 
